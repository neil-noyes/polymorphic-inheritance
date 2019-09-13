//Author : Neil Noyes

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "killerant.h"
#include "bug.h"
using namespace std;
using namespace GameSpace;

const int KillerAnt::INIT_VAR_STATS[PlayerClass::NUM_STATS] = {20,7,2,5,10,-1,-1,2,0,0};
const int KillerAnt::INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS] = {20,2,2,6};

KillerAnt::KillerAnt():Bug("",INIT_CONST_STATS,INIT_VAR_STATS)
{
	
	//empty body - inaccesable constructor
}

KillerAnt::KillerAnt(string name):Bug(name,INIT_CONST_STATS,INIT_VAR_STATS)
{
	//empty body
}

string KillerAnt::TypeStr() const{
	
	return "KILLERANT";
}

bool KillerAnt::IsMyEnemy(const PlayerClass::PlayerClass* p) const{
	
	bool enemy = false;
	if (p){
		if (!dynamic_cast<KillerAnt*>(const_cast<PlayerClass*>(p))){
			enemy = true;
		}
	}
	return enemy;
}

void KillerAnt::Write(ostream& out) const{
	
	out << TypeStr();
	Bug::Write(out);
}

PlayerClass* KillerAnt::Clone() const {
	
	return new KillerAnt(*this);
}