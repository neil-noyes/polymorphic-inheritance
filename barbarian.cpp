//Author: Neil Noyes
//Program: 4

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "wpn.h"
#include "human.h"
#include "barbarian.h"
using namespace std;
using namespace GameSpace;

const int Barbarian::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {100,4,4,6};
const int Barbarian::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {100,11,4,11,10,-1,-1,4,0,0};

Barbarian::~Barbarian(){

}

Barbarian::Barbarian():Human("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
}

Barbarian::Barbarian(string name):Human(name, INIT_CONST_STATS, INIT_VAR_STATS)
{
	
}

string Barbarian::TypeStr() const{
	
	return "BARBARIAN";
}

bool Barbarian::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	bool enemy = false;
	if (p != NULL){
		if ((p) != this){
			enemy = true;
		}
	}
	return enemy;
}

void Barbarian::Write(ostream& out) const{
	
	out << TypeStr();
	Human::Write(out);
}

PlayerClass* Barbarian::Clone() const {
	
	return new Barbarian(*this);
}

bool Barbarian::Heal(){
	
	bool healed = false;
	if (IsActive() && IsAlive()){
		
		Invigorate(5);
		ResetCurrentSpeed();		
		healed = true;						
	}
	
	return healed;
}

int Barbarian::HitDamage() const{
	
	int multiplier = (WillPower()/2) + ((WillPower() % 2) != 0);
	int dmg = 0;
	
	if (IsActive()){
		
		if (heldWpn){
			
			
			string wpnToFind = heldWpn->Name();
			transform(wpnToFind.begin(),wpnToFind.end(),wpnToFind.begin(), ::toupper);
			map<string,int>::const_iterator iter = WpnSkill.find(wpnToFind);
			
			int wSkill = 0;
			
			if (iter != WpnSkill.end()){
				wSkill = iter->second;
			}
			
			int wpnRoll = static_cast<const Weapon*>(heldWpn)->RollWeaponDamage(PlayerClass::Name());
			dmg = wSkill + wpnRoll;
		}
		else{
			
			dmg = Power() + RollPhysDam();		
		}	
		
	}
	
	return (dmg*multiplier);
}



