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
#include "warrior.h"
using namespace std;
using namespace GameSpace;

const int Warrior::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {81,5,3,6};
const int Warrior::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {81,9,5,9,8,-1,-1,5,0,0};

Warrior::~Warrior(){

}

Warrior::Warrior():Human("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
}

Warrior::Warrior(string name):Human(name, INIT_CONST_STATS, INIT_VAR_STATS)
{
	
}

string Warrior::TypeStr() const{
	
	return "WARRIOR";
}

bool Warrior::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	Human::IsMyEnemy(p);
}

void Warrior::Write(ostream& out) const{
	
	out << TypeStr();
	Human::Write(out);
}

PlayerClass* Warrior::Clone() const {
	
	return new Warrior(*this);
}