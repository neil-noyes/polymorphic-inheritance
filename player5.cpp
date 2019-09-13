//Author: Neil Noyes
//Program: 4

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
using namespace std;
using namespace GameSpace;

const int PlayerClass::NUM_STATS;
const int PlayerClass::NUM_CONST_STATS;
const int PlayerClass::W = -1;
const int PlayerClass::POW_RATINGS;
const int PlayerClass::ROLL_VALUES;

const int PlayerClass::k = 0;


		const int PlayerClass::ImpactTable[ROLL_VALUES+1][POW_RATINGS+1] = 
		{
			/*						Power Rating
		     1	    2     3     4     5     6     7     8    9     10    11	 12   */
			{0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,	  0	 }, // 1
			{0,    0,    1,    2,    3,    4,    5,    6,    7,    8,    9,	 10  }, // 2
			{0,    1,    2,    3,    4,    5,    6,    7,    8,    9,   10,	  W  }, // 3
			{0,    2,    3,    4,    5,    6,    7,    8,    9,   10,    W,	  W  }, // 4
			{0,    3,    4,    5,    6,    7,    8,    9,   10,    W,    W,	  W	 },	// 5
			{0,    4,    5,    6,    7,    8,    9,   10,    W,    W,    W,   W  },	// 6	Roll Values
			{0,    5,    6,    7,    8,    9,   10,    W,    W,    W,    W,   W	 },	// 7
			{0,    6,    7,    8,    9,   10,    W,    W,    W,    W,    W,   W	 },	// 8
			{0,    7,    8,    9,   10,    W,    W,    W,    W,    W,    W,	  W	 }, // 9
			{0,    8,    9,   10,    W,    W,    W,    W,    W,    W,    W,	  W	 },	// 10
			{0,    9,   10,    W,    W,    W,    W,    W,    W,    W,    W,	  W	 },	// 11
			{0,   10,    W,    W,    W,    W,    W,    W,    W,    W,    W,	  W	 }	// 12
		};
		

		const int PlayerClass::CritTable[ROLL_VALUES+1][POW_RATINGS+1] = 
		{
			/*					    WillPower Rating
		       1    2	  3     4     5     6     7     8     9   10    11   12 	*/
			{   0, 	0,    0,    0,    0,    0,    0,    0,    0,   0,    0,   0}, // 1
			{	0,  k,    k,    k,    k,    k,    k,    k,    k,   k,    k,  -1}, // 2
			{	0,  k,    k,    k,    k,    k,    k,    k,    k,   k,   -1,  -1}, // 3
			{	0,  k,    k,    k,    k,    k,    k,    k,    k,  -1,   -1,  -1}, // 4
			{	0,  k,    k,    k,    k,    k,    k,    k,   -1,  -1,   -1,  -1}, // 5
			{	0,  k,    k,    k,    k,    k,    k,   -1,   -1,  -1,   -1,  -1}, // 6	Roll Values
			{	0,  k,    k,    k,    k,    k,   -1,   -1,   -1,  -1,   -1,  -1}, // 7
			{	0,  k,    k,    k,    k,   -1,   -1,   -1,   -1,  -1,   -1,  -1}, // 8
			{	0,  k,    k,    k,   -1,   -1,   -1,   -1,   -1,  -1,   -1,  -1}, // 9
			{	0,  k,    k,   -1,   -1,   -1,   -1,   -1,   -1,  -1,   -1,  -1}, // 10
			{	0,  k,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  -1,   -1,  -1}, // 11
			{   0, -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  -1,   -1,  -1}  // 12			
		};			
		

	
string PlayerClass::CheckName(string n){

	string temp;
	if (n.length() < 1 || n == " " || TrimStr(n) == ""){
		throw INVALID_NAME;
	}
	else{
		temp = TrimStr(n);
		if (temp.length() > 10){
			temp.resize(10);
		}
	
	}
	temp = TrimStr(temp);
	return temp;
}
	
bool PlayerClass::SetStats(const int VAR_STATS[]){

		for (int i = HEALTH; i < NUM_STATS; ++i){
			Stats[i] = VAR_STATS[i];
		}	
}

PlayerClass::~PlayerClass(){
	
}

PlayerClass::PlayerClass():STATS(NULL)
{

}

PlayerClass::PlayerClass(string pname, const int CONST_STATS[], const int VAR_STATS[]):NAME(CheckName(pname)),
																					STATS(CONST_STATS)
{

	SetStats(VAR_STATS);
}

string PlayerClass::Name() const{

	return NAME;
	
}

int PlayerClass::Row() const{

	return Stats[ROW];
	
}

int PlayerClass::Col() const{

	return Stats[COL];
	
}

GameSpace::DirType PlayerClass::Dir() const{
	
	DirType direction = static_cast<DirType>(Stats[DIRECTION]);
	return direction;
	
}

int PlayerClass::MaxHealth() const{
	
	return STATS[MAX_HEALTH];
	
}

int PlayerClass::Health() const{
	
	return Stats[HEALTH];
	
}

int PlayerClass::WillPower() const{
		
	return Stats[WILLPOWER];
	
}

int PlayerClass::MaxSpeed() const{
	
	return STATS[MAX_SPEED];
	
}

int PlayerClass::CurrentSpeed() const{
		
	return Stats[CURRENT_SPEED];
	
}

int PlayerClass::Momentum() const{
	
	return Stats[MOMENTUM];
	
}

int PlayerClass::Power() const{
	
	return Stats[POWER];
	
}

int PlayerClass::Defense() const{
	
	return Stats[DEFENSE];
	
}

bool PlayerClass::IsAlive() const{
	
	bool alive = false;
	if (Stats[HEALTH] > 0){
		alive = true;
	}
	return alive;
	
}

bool PlayerClass::IsDead() const{
	
	bool death = false;
	
	if (Stats[HEALTH] <= 0){
		death = true;
	}
	
	return death;
		
}

bool PlayerClass::IsActive() const{
	
	return Stats[ACTIVITY];
	
}


bool PlayerClass::MakeActive(){
		
	if (IsAlive())
		Stats[ACTIVITY] = true;
	else 
		Stats[ACTIVITY] = false;
	
	return Stats[ACTIVITY];
}

bool PlayerClass::MakeInActive(){
	
	Stats[ACTIVITY] = false;
	
	return true;
}

bool PlayerClass::MakeDead(){


	Stats[HEALTH] = 0;
	Stats[WILLPOWER] = 0;
	Stats[MOMENTUM] = 0;
	Stats[CURRENT_SPEED] = 0;
	Stats[ACTIVITY] = false;

	return true;
}

int PlayerClass::Wounded(int damage){
	
	if (IsActive() && damage > 0){
		
		if (Stats[HEALTH]-damage <= 0){
			MakeDead();
		}
		else{
			Stats[HEALTH] = Stats[HEALTH]-damage;
		}
		
	}
	
	return Stats[HEALTH];
}

int PlayerClass::Invigorate(int vigor){
	
	if (IsActive() && vigor > 0 && IsAlive()){
		
		Stats[HEALTH] = Stats[HEALTH] + vigor;
		
		if (Stats[HEALTH] > STATS[MAX_HEALTH]){
			Stats[HEALTH] = STATS[MAX_HEALTH];
		}
	}
	
	return Stats[HEALTH];
}

bool PlayerClass::Heal(){

	bool healed = false;
	
	if (IsActive() && IsAlive()){
		
		Stats[HEALTH] = Stats[HEALTH] + 10;
		if (Stats[HEALTH] > STATS[MAX_HEALTH]){
			Stats[HEALTH] = STATS[MAX_HEALTH];
		}
		
		Stats[CURRENT_SPEED] = STATS[MAX_SPEED];
		healed = true;
		
	}
	
	return healed;
}

int PlayerClass::SlowDown(int hazard){

	if (IsActive() && hazard > 0){
		
		Stats[CURRENT_SPEED] = Stats[CURRENT_SPEED] - hazard;
		
		if (Stats[CURRENT_SPEED] < 0)
			Stats[CURRENT_SPEED] = 0;
		
		if (Stats[MOMENTUM] > Stats[CURRENT_SPEED])
			Stats[MOMENTUM] = Stats[CURRENT_SPEED];
		
	}
	
	return Stats[CURRENT_SPEED];	
}

int PlayerClass::ResetCurrentSpeed(){
	
	if (IsActive())
		Stats[CURRENT_SPEED] = STATS[MAX_SPEED];
	
	return Stats[CURRENT_SPEED];
}

int PlayerClass::ResetMomentum(){

	if (IsActive())
		Stats[MOMENTUM] = Stats[CURRENT_SPEED];
	
	return Stats[MOMENTUM];
}

int PlayerClass::UseMomentum(int amount){
	
	if (IsActive() && amount > 0){
		
		Stats[MOMENTUM] = Stats[MOMENTUM] - amount;
		
		if (Stats[MOMENTUM] < 0)
			Stats[MOMENTUM] = 0;
		
	}
	
	return Stats[MOMENTUM];
}

bool PlayerClass::SetCell(int newRow, int newCol){

	bool worked = false;
	
	if (newRow >= -1 && newCol >= -1){ 
		
		
		if (newRow == -1 && newCol != -1){
			worked = false;
		}
		else if (newCol == -1 && newRow != -1){
			worked = false;
		}
		else if (newRow >= -1 && newCol >= -1 && newCol <= GameSpace::NUMCOLS && newRow <= GameSpace::NUMROWS){
			Stats[ROW] = newRow;
			Stats[COL] = newCol;
			worked = true;				
		}
	
	}
	
	return worked;
}

bool PlayerClass::SetDir(DirType dir){
	
	bool dirSet = false;
	
	if (dir >= 0 && dir <= WEST){
		switch (dir){
			
			case NORTH:
				Stats[DIRECTION] = NORTH;
				dirSet = true;
				break;
			case SOUTH:
				Stats[DIRECTION] = SOUTH;
				dirSet = true;
				break;
			case EAST:
				Stats[DIRECTION] = EAST;
				dirSet = true;
				break;
			case WEST:
				Stats[DIRECTION] = WEST;
				dirSet = true;
				break;
			default:
				Stats[DIRECTION] = NORTH;
				dirSet = true;
				break;
		}
	}
	
	return dirSet;
}

void PlayerClass::Write(ostream& out) const{
	

		out << "#" << IsActive() << "#" << NAME << "#" << "(" << Stats[ROW] << "," << Stats[COL] << "," << DIR_CHAR[Stats[DIRECTION]] << ")"
			<< "#" << STATS[MAX_HEALTH] << "#" << Stats[HEALTH] << "#" << Stats[WILLPOWER] << "#" << Stats[POWER] << "#" << STATS[MAX_SPEED] << "#" 
			<< Stats[CURRENT_SPEED] << "#" << Stats[MOMENTUM] << "#" << STATS[NUMDIE] << "d" << STATS[NUMSIDES] << "#" << 
			Stats[DEFENSE] << endl;
			
		
}

int PlayerClass::RollPhysDam() const{
	
	int rollVal = 0;

	rollVal = Dice::Roll(NAME,GameSpace::DAMAGE,STATS[NUMDIE],STATS[NUMSIDES]);
	
	return rollVal;
}

int PlayerClass::Fortify(int boost){
	
	if (IsActive() && boost > 0){
		
		Stats[DEFENSE] = Stats[DEFENSE] + boost;
	}
	
	return Stats[DEFENSE];
}

int PlayerClass::Expose(int decline){
	
	if (IsActive() && decline > 0){
		
		Stats[DEFENSE] = Stats[DEFENSE] - decline;
		
		if (Stats[DEFENSE] < 0){
			
			Stats[DEFENSE] = 0;
		}
		
	}
	
	return Stats[DEFENSE];
}

int PlayerClass::Impact() const{
	
	int imp = 0;
	
	if (IsActive()){
		
		
		int rollVal = RollImpact();
		
		
		if (Stats[POWER] < 2){
			imp = 0;
		}
		else{
			imp = PlayerClass::ImpactTable[(rollVal-1)][(Stats[POWER]-1)];
		}
			
	}
	
	return imp;
}

int PlayerClass::RollImpact() const{
	int rollVal = Dice::Roll(NAME,GameSpace::IMPACT,2,6);
		
	if (rollVal < 2 || rollVal > 12)
		throw INVALID_ROLL;
	
	return rollVal;
}
int PlayerClass::LookupImpact(int power, int roll) const{
	
	int tableVal = 0;
	
	if (Power() >= 2){
		tableVal = PlayerClass::ImpactTable[(roll-1)][(power-1)];
	}
	
	return tableVal;
}

int PlayerClass::WillPowerAdj(int adj){
	
	if (IsActive()){
		Stats[WILLPOWER] += adj;
		
		if (Stats[WILLPOWER] < 0){
			Stats[WILLPOWER] = 0;
			MakeDead();
		}
		else if (Stats[WILLPOWER] > 12){
			Stats[WILLPOWER] = 12;
		}
	}
	
	return Stats[WILLPOWER];
}

int PlayerClass::HitScore() const{
	
	int rollVal = 0;
	
	int die = 2;
	int faces = 6;
	
	if (IsActive()){
		rollVal = Dice::Roll(NAME,GameSpace::HITSCORE,die,faces);
	}
	
	return rollVal;
}

int PlayerClass::HitDamage() const{
	
	int dmg = 0;
	
	if (IsActive()){

		dmg = Stats[POWER] + Dice::Roll(NAME,GameSpace::DAMAGE,STATS[NUMDIE],STATS[NUMSIDES]);
		
	}
	
	return dmg;
}

bool PlayerClass::CriticalWound(){

	bool stillAlive;
	
	if (IsActive()){

		if (Health() > 10 && WillPower() > 1 && WillPower() <= 12){	
			
			
			int die = 2;
			int faces = 6;
			
			int rollVal = Dice::Roll(NAME,GameSpace::WOUND,die,faces);
			if (rollVal < 2 || rollVal > 12)
				throw INVALID_ROLL;
				
			Stats[HEALTH] -= 10;
			Stats[CURRENT_SPEED] = floor((Stats[CURRENT_SPEED]/2));
			if (Stats[MOMENTUM] > Stats[CURRENT_SPEED]){
				Stats[MOMENTUM] = Stats[CURRENT_SPEED];
			}	
			
			
			if (CritTable[(rollVal-1)][(Stats[WILLPOWER]-1)] == -1){
				WillPowerAdj(-1);
				stillAlive = true;
			}
			else{
				MakeDead();
				stillAlive = false;
			}
			
		}
		else{
			MakeDead();
			stillAlive = false;
		}
	
	}
	else if(!IsActive() && IsAlive()){
		stillAlive = true;
	}
	else{
		stillAlive = false;
	}
	
	return stillAlive;
	
}


void PlayerClass::CopyToMe(const PlayerClass& player)
{
	
	*(const_cast<string*>(&NAME)) = player.NAME;
	*(const_cast<const int**>(&STATS)) = player.STATS;
	
	
	for (int i = 0; i < NUM_STATS; ++i){
		Stats[i] = player.Stats[i];
	}

}

PlayerClass::PlayerClass(const PlayerClass& player):NAME(player.Name()),
													STATS(player.STATS)
{

	CopyToMe(player);
}

PlayerClass& PlayerClass::operator=(const PlayerClass& player){
	
	if (this != &player){

		CopyToMe(player);
	}
	
	return *this;
}

bool PlayerClass::operator==(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine == theirs);
}

bool PlayerClass::operator!=(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine != theirs);
}

bool PlayerClass::operator<(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine < theirs);
}

bool PlayerClass::operator>(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine > theirs);
}

bool PlayerClass::operator<=(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine <= theirs);
}

bool PlayerClass::operator>=(const PlayerClass& p) const{
	
	string mine = NAME;
	string theirs = p.Name();
	transform(mine.begin(),mine.end(),mine.begin(), ::toupper);
	transform(theirs.begin(),theirs.end(),theirs.begin(), ::toupper);
	
	return (mine >= theirs);
}

ostream& operator<<(ostream& out, const PlayerClass* p){

	p->Write(out);
}

