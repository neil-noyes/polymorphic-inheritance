//Author : Neil Noyes

#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "bug.h"
#include "gamespace.h"
#include "dice.h"
using namespace std;
using namespace GameSpace;


Bug::Bug():PlayerClass("",NULL,NULL)
{
	
	//empty body - inaccessible constructor
}

Bug::Bug(const string inName, const int CONST_STATS[], const int VAR_STATS[]):PlayerClass(inName,
																						CONST_STATS,
																						VAR_STATS)

{
	
	//empty body
}

void Bug::Write(ostream& out) const{
	PlayerClass::Write(out);
}

bool Bug::IsMyEnemy(const PlayerClass* p) const{
	
}