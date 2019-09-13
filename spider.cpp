//Author : Neil Noyes

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "spider.h"
#include "bug.h"
using namespace std;
using namespace GameSpace;

const int Spider::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {50,8,15,11,7,-1,-1,15,0,0};
const int Spider::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {50,15,2,6};

Spider::Spider():Bug("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
	//empty body - inaccesable constructor
}

Spider::Spider(string name):Bug(name,INIT_CONST_STATS,INIT_VAR_STATS)
{
	//empty body
}

string Spider::TypeStr() const{
	
	return "SPIDER";
}

bool Spider::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	bool enemy = false;
	if (p){
		if (!dynamic_cast<Spider*>(const_cast<PlayerClass*>(p))){
			enemy = true;
		}
	}
	return enemy;
}

void Spider::Write(ostream& out) const{
	
	out << TypeStr();
	Bug::Write(out);
}

PlayerClass* Spider::Clone() const {
	
	return new Spider(*this);
}