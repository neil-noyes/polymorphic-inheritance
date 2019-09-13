//Author : Neil Noyes

#ifndef BUG_H
#define BUG_H

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"

using namespace std;
using namespace GameSpace;

class Bug: public PlayerClass
{
	
	public:
		virtual void Write(ostream& out) const;
		virtual bool IsMyEnemy(const PlayerClass* p) const = 0;
		virtual PlayerClass* Clone() const = 0;
		
	protected:
		Bug(const string NAME, const int CONST_STATS[], const int VAR_STATS[]);
	
	private:
		Bug();
	
};

#endif