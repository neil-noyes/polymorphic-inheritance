//Author: Neil Noyes
//Program: 4

#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "gamespace.h"
#include "dice.h"
using namespace std;
using namespace GameSpace;

class PlayerClass{

	protected:
		PlayerClass(const string inName, const int CONST_STATS[], const int VAR_STATS[]);
		/*
		Narrative: Player Construction
		Pre: Constructor
		Post: Player created
		*/	
		int RollImpact() const;
		/*
		Narrative: Rolls for impact
		Pre: n/a
		Post: returns roll for impact
		*/	
		int LookupImpact(int power, int roll) const;
		/*
		Narrative: looks up value from impact table
		Pre: power and roll are validated
		Post: returns table value
		*/	

	
	public:
		static const int NUM_STATS = 10;
		static const int NUM_CONST_STATS = 4;
		static const int W;
		static const int k;

		PlayerClass& operator=(const PlayerClass& p);
		/*
		Narrative: Player Assignment Operator
		Pre: Valid player parameter
		Post: player parameter copied into self as long as self assignment isnt attempted
		*/		
		
		PlayerClass(const PlayerClass& player);
		/*
		Narrative: Player Copy Construction
		Pre: Valid player parameter
		Post: player parameter copied into self
		*/	
		
		
		virtual ~PlayerClass();
		/*
		Narrative: Player Destructor
		Pre: Construction of object complete
		Post: Player destructed
		*/			
		
		virtual PlayerClass* Clone() const = 0;
		
		
		string Name() const;
		/*
		Narrative: Returns the name of a player as a string
		Pre: Construction of object complete
		Post: Name of player will return
		*/	
		
		
		int Row() const;
		/*
		Narrative: Returns the row of the players current cell
		Pre: Construction of object complete
		Post: Current row will return
		*/		

		int Col() const;
		/*
		Narrative: Returns the current column of the players current cell
		Pre: Construction of object complete
		Post: Current column will return
		*/			
		
		GameSpace::DirType Dir() const;
		/*
		Narrative: Returns the direction of a player
		Pre: Construction of object complete
		Post: direction will return
		*/			
		
		int MaxHealth() const;
		/*
		Narrative: Returns the max health of a player 
		Pre: Construction of object complete
		Post: maxHealth will return
		*/			
		
		int Health() const;
		/*
		Narrative: Returns the current health of a player
		Pre: Construction of object complete
		Post: current health will return
		*/			
		
		int WillPower() const;
		/*
		Narrative: Returns the willPower of a player
		Pre: Construction of object complete
		Post: willPower will return
		*/			
		
		int MaxSpeed() const;
		/*
		Narrative: returns the max speed of a player
		Pre: Construction of object complete
		Post: maxSpeed will return
		*/			
		
		int CurrentSpeed() const;
		/*
		Narrative: returns the current speed of a player
		Pre: Construction of object complete
		Post: currentSpeed will return
		*/			
		
		int Momentum() const;
		/*
		Narrative: Returns the current momentum of a player
		Pre: Construction of object complete
		Post: momentum will return
		*/			
		
		int Power() const;
		/*
		Narrative: returns the power of a player
		Pre: Construction of object complete
		Post: power will return
		*/			
		
		virtual int RollPhysDam() const;
		/*
		Narrative: Rolls dice for damage
		Pre: Construction of object complete
		Post: int value will be returned to indicate roll for damage
		*/			
		
		int Defense() const;
		/*
		Narrative: Returns the defense value of a player
		Pre: Construction of object complete
		Post: defense value will return
		*/				
		
		virtual bool IsAlive() const;
		/*
		Narrative: Returns true if the player is alive, false otherwise
		Pre: Construction of object complete
		Post: will return a bool indicating if the player if alive
		*/			
		
		virtual bool IsDead() const;
		/*
		Narrative: Returns true if the player is dead, false otherwise
		Pre: Construction of object complete
		Post: will return a bool indicating if the player is dead
		*/			
		
		virtual bool IsActive() const;
		/*
		Narrative: Returns true if the player is active, false otherwise
		Pre: Construction of object complete
		Post: will return a bool indicating if the player is active
		*/			
		
		virtual bool IsMyEnemy(const PlayerClass* p) const = 0;
		/*
		Narrative: Will return true if p points to an enemy player (all bugs enemies are other types of bugs
		and humans have enemies of all bugs.
		Pre: Construction of object complete
		Post: will return a bool indicating if p points to an enemy player
		*/
		
		virtual bool MakeActive();
		/*
		Narrative: Sets the player to active as long as they are not dead
		Pre: Construction of object complete
		Post: returns a bool indicating the activity of the player (true for active, false for inactive)
		*/			
		
		virtual bool MakeInActive();
		/*
		Narrative: Sets the player to inactive
		Pre: Construction of object complete
		Post: activity will be set to false - returns true 
		*/			
		
		virtual bool MakeDead();
		/*
		Narrative: Sets all corresponding values of a player to indicate death
		Pre: Construction of object complete
		Post: Appropriate values will be set to 0, player will be set to inactive, will return true
		*/		
		
		int Wounded(int damage);
		/*
		Narrative: Sets health to health - damage as long as the player is active and damage is > 0.
		If health then drops to or below 0, player is made dead
		Pre: Construction of object complete
		Post: health will be returned after damage is taken
		*/		
		
		int Invigorate(int vigor);
		/*
		Narrative: Sets health to health + vigor as long as the player is active, alive, and vigor  > 0
		Pre: Construction of object complete
		Post: returns health after being invigorated (or health with no change)
		*/			
		
		virtual bool Heal();
		/*
		Narrative: Adds 10 to health and resets speed to max speed as long as player is alive and active
		Pre: Construction of object complete
		Post: will return a bool indicating if player was able to be healed
		*/			
		
		int SlowDown(int hazard);
		/*
		Narrative: Sets current speed to current speed - hazard as long as 
		player is active and hazard > 0
		If then momentum is less than current speed, momentum is set to the curernt speed
		Pre: Construction of object complete
		Post: current speed of player is returned
		*/			
		
		int ResetCurrentSpeed();
		/*
		Narrative: Resets current speed to max speed as long as the player is active
		Pre: Construction of object complete
		Post: current speed of player will be returned
		*/		
		
		int ResetMomentum();
		/*
		Narrative: resets mementum to current speed as long as the player is active
		Pre: Construction of object complete
		Post: momentum of the player will be returned
		*/			
		
		int UseMomentum(int amount);
		/*
		Narrative: Reduces momentum by amount as long as player is active and amount > 0
		If then momentum drops below 0, momentum is then set to 0
		Pre: Construction of object complete
		Post: momentum of the player will return
		*/			
		
		bool SetCell(int newRow, int newCol);
		/*
		Narrative: Sets the current cell of a player as long as newRow and newCol are in bounds
		Pre: Construction of object complete
		Post:a bool will return indicating a successful or unsuccessful setting of a cell
		*/		
		
		bool SetDir(DirType dir);
		/*
		Narrative: Sets the direction of a player as long as dir is within range of enum DIRTYPE
		Pre: Construction of object complete
		Post: a bool will return indicating a successful or unsuccessful setting of direction
		*/			
		
		virtual void Write(ostream& out) const;
		/*
		Narrative: outputs player data
		Pre: Construction of object complete
		Post: player data will be output in the correct form
		*/			
		
		int Fortify(int boost);
		/*
		Narrative: Adds boost to an active player's defense value
		Pre: Construction of object complete
		Post: Defense value returned
		*/		
		
		int Expose(int decline);
		/*
		Narrative: Subtracts decline from an active player's defense value
		Pre: Construction of object complete
		Post: Defense value returned
		*/	
		
		virtual int Impact() const;
		/*
		Narrative: Returns impact pf critical wound if player is active, otherwise 0
		Pre: Construction of PlayerClass object complete
		Post: Impact deciding factor returned (value from Impact Table)
		*/
		
		int WillPowerAdj(int adj);
		/*
		Narrative: Modifies willpower and returns the new value so long as it is between 0 & 12
		Pre: Construction of player class object complete
		Post: returns willPower 
		*/
		
		virtual int HitScore() const;
		/*
		Narrative: Returns a value of a rolled hit score if the player is active, otherwise 0
		Pre: Construction of PlayerClass object complete
		Post: hit score value is returned as an int
		*/
		
		virtual int HitDamage() const;
		/*
		Narrative: Retutns damage inflicted value
		Pre: Construction of PlayerClass object complete
		Post: damage inflicted is returned as an int
		*/		
		
		
		virtual bool CriticalWound();
		/*
		Narrative: Applieds outcome of a critical wound on an active player.
		Pre: Construction of PlayerClass object complete
		Post: Returns true if a player is still alive... false otherwise
		*/		
		
		virtual string TypeStr() const = 0;
		/*
		Narrative: For vtable entry use here
		Pre/Post: N/a
		*/

	
	// Boolean Operators**************************************	
		bool operator==(const PlayerClass& p) const;
		bool operator!=(const PlayerClass& p) const;
		bool operator<(const PlayerClass& p) const;
		bool operator>(const PlayerClass& p) const;
		bool operator<=(const PlayerClass& p) const;
		bool operator>=(const PlayerClass& p) const;		
		
		
	private:
		
		PlayerClass();		
		/* Unused - Prevents no parameter construction
		Narrative: Player Construction
		Pre: Constructor
		Post: N/A
		*/			

		const string NAME;
		int Stats[NUM_STATS];
		const int* const STATS;
		
		enum StatType{
			HEALTH,
			WILLPOWER,
			CURRENT_SPEED,
			POWER,
			DEFENSE,
			ROW,
			COL,
			MOMENTUM,
			DIRECTION,
			ACTIVITY,
		};
		
		enum ConstStatType{
			MAX_HEALTH,
			MAX_SPEED,
			NUMDIE,
			NUMSIDES,
		};


		static const int POW_RATINGS = 11;
		static const int ROLL_VALUES = 11;
		static const int ImpactTable[ROLL_VALUES+1][POW_RATINGS+1];
		static const int CritTable[ROLL_VALUES+1][POW_RATINGS+1];
		
	
	//Helper Functions****************************************
		string CheckName(string n);
		/*
		Narrative: *Helper* Checks to see if name passed into constructor is valid and corrects it
		Pre: *construction helper*
		Post: Name of a player is validated, then set
		*/		
		
		void CopyToMe(const PlayerClass& player);
		/*
		Narrative: *Helper* Copies one player to another
		Pre: *copy construction/assign op helper*
		Post: Passed in player data assigned to our own
		*/	
		
		bool SetStats(const int VAR_STATS[]);
		/*
		Narrative: *Helper* Sets the stats of a player during creation
		Pre: *construction helper*
		Post: Stats of a player are set depending on the type of player passed in
		*/	

};

ostream& operator<<(ostream& out, const PlayerClass* p);
/*
Narrative: overloaded insertion operator
Pre: Construction of object complete
Post: will output player data in the correct form
*/	


#endif	