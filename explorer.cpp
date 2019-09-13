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
#include "explorer.h"
using namespace std;
using namespace GameSpace;

const int Explorer::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {42,8,1,6};
const int Explorer::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {42,7,8,6,0,-1,-1,8,0,0};

Explorer::~Explorer(){

}


Explorer::Explorer():Human("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
}

Explorer::Explorer(string name):Human(name, INIT_CONST_STATS, INIT_VAR_STATS)
{
	
}

string Explorer::TypeStr() const{
	
	return "EXPLORER";
}

bool Explorer::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	Human::IsMyEnemy(p);
}

void Explorer::Write(ostream& out) const{
	
	out << TypeStr();
	Human::Write(out);
}

PlayerClass* Explorer::Clone() const {
	
	return new Explorer(*this);
}