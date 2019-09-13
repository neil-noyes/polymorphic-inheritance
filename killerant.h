//Author : Neil Noyes

#ifndef KILLERANT_H
#define KILLERANT_H

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "bug.h"
using namespace std;
using namespace GameSpace;

class KillerAnt: public Bug
{
	public:
		
		KillerAnt(string name);
		
		void Write(ostream& out) const;
		bool IsMyEnemy(const PlayerClass::PlayerClass* p) const;
		string TypeStr() const;
		
		PlayerClass* Clone() const;

	private:
		KillerAnt();
		static const int INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS];
		static const int INIT_VAR_STATS[PlayerClass::NUM_STATS];	
};

#endif