//Author: Neil Noyes
//Program: 4
#ifndef EXPLORER_H
#define EXPLORER_H

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "wpn.h"
#include "human.h"
using namespace std;
using namespace GameSpace;


class Explorer: public Human
{
	public:
		~Explorer();
		Explorer(string name);
		void Write(ostream& out) const;
		string TypeStr() const;
		bool IsMyEnemy(const PlayerClass::PlayerClass* p) const;
		PlayerClass* Clone() const;
		
	private:
		Explorer();
		static const int INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS];
		static const int INIT_VAR_STATS[PlayerClass::NUM_STATS];
	
};

#endif