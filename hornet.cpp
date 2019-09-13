//Author : Neil Noyes

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "hornet.h"
#include "bug.h"
using namespace std;
using namespace GameSpace;

const int Hornet::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {60,9,8,10,8,-1,-1,8,0,0};
const int Hornet::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {60,8,3,6};

Hornet::Hornet():Bug("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
	//empty body - inaccesable constructor
}

Hornet::Hornet(string name):Bug(name,INIT_CONST_STATS,INIT_VAR_STATS)
{
	//empty body
}

string Hornet::TypeStr() const{
	
	return "HORNET";
}

bool Hornet::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	bool enemy = false;
	
	if (p){
		if (!dynamic_cast<Hornet*>(const_cast<PlayerClass*>(p))){
			enemy = true;
		}
	}
	return enemy;
}

void Hornet::Write(ostream& out) const{
	
	out << TypeStr();
	Bug::Write(out);
}

PlayerClass* Hornet::Clone() const {
	
	return new Hornet(*this);
}

