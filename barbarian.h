//Author: Neil Noyes
//Program: 4
#ifndef BARBARIAN_H
#define BARBARIAN_H

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


class Barbarian: public Human
{
	public:
		~Barbarian();
		Barbarian(string name);
		void Write(ostream& out) const;
		string TypeStr() const;
		bool IsMyEnemy(const PlayerClass::PlayerClass* p) const;
		PlayerClass* Clone() const;
		bool Heal();
		int HitDamage() const;
		
	private:
		Barbarian();
		static const int INIT_CONST_STATS[PlayerClass::NUM_CONST_STATS];
		static const int INIT_VAR_STATS[PlayerClass::NUM_STATS];
	
};

#endif