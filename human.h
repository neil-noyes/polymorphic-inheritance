//Author: Neil Noyes

#ifndef HUMAN_H
#define HUMAN_H

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "wpn.h"
#include "pack.h"

using namespace std;
using namespace GameSpace;


class Human: public PlayerClass
{
	
	public:
		
	//CONSTRUCTION	
		~Human();
		Human& operator=(const Human&);
		Human(const Human&);
	
	
	//OBSERVERS
		virtual void Write(ostream& out) const;
		
		virtual string TypeStr() const = 0;
		
		virtual bool IsMyEnemy(const PlayerClass* p) const = 0;
		
		virtual PlayerClass* Clone() const = 0;
		
		bool ImprovedSkill(int improvement);
		/*
		Narrative: Returns true if skill of current weapon can be improved
		Pre: Cionstruction PlayerClass of object complete
		Post: bool indicating if skill for current weapon can be improved or not
		*/
		
		int WeaponSkill() const;
		/*
		Narrative: Returns weapon skill of held weapon
		Pre: Construction of object complete
		Post: Weapon skill of weapon in hand returned (or 0 if no weapon)
		*/			
		
		Weapon* GrabWeapon(Weapon* weapon);
		/*
		Narrative: puts current weapon in pack if there is one and grabs the one passed in
		as long as it is not null. Also adds unknown weapons to map or weapon skill
		Pre: PlayerClass instance created
		Post: Weapon dropped returned (or NULL if there wasn't a weapon to drop)
		*/
		
		Weapon* DropWeapon();
		/*
		Narrative: drops/removes from pack an active nonbugs current weapon if there is one
		Pre: PlayerClass instance created
		Post: Weapon dropped returned (or NULL if there wasn't a weapon to drop/inactive/bug)
		*/	
		
		Weapon* ChangeWeapon(string weaponName);
		/*
		Narrative: changes carried weapon
		Pre: PlayerClass instance created
		Post: Weapon dropped returned (or NULL if there wasn't a weapon to drop/inactive/bug)
		*/	
		
		vector<string> Pack() const;
		/*
		Narrative: returns names of weapons in pack
		Pre: PlayerClass instance created
		Post: vector of weapon names returned
		*/	
		
		bool HasWeapon() const;
		/*
		Narrative: Returns true if the player has a weapon
		Pre: Construction of PlayerClass object complete
		Post: Bool indicating if the player has a weapon is returned
		*/	
		
		string WeaponName() const;
		/*
		Narrative: Returns weapon name or empty string if there is no weapon
		Pre: Construction of PlayerClass object complete
		Post: returns weapon name or empty string
		*/		
		
		string WeaponNameAndNum() const;
		/*
		Narrative: Returns weapon name and num or empty string if there is no weapon
		Pre: Construction of PlayerClass object complete
		Post: returns weapon name and num or empty string
		*/		
	//COMBAT	
		int Impact() const;
		/*
		Narrative: Returns impact pf critical wound if player is active, otherwise 0
		Pre: Construction of PlayerClass object complete
		Post: Impact deciding factor returned (value from Impact Table)
		*/	

		int HitDamage() const;
		/*
		Narrative: Retutns damage inflicted value
		Pre: Construction of PlayerClass object complete
		Post: damage inflicted is returned as an int
		*/	

		
	protected:
		Human(const string NAME, const int CONST_STATS[], const int VAR_STATS[]);
		map <string, int> WpnSkill;
		Weapon* heldWpn;
		PackClass* const pack;
		
	private:
		Human();
	//HELPER			
		void CopyToHuman(const Human& h);
		PackClass* GetPackAddress() const;
		PackClass* CopyPack(const PackClass* p) const;
		
};

#endif