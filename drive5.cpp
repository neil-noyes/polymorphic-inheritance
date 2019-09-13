#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include "player5.h"
#include "gamespace.h"
#include "dice.h"
#include "wpn.h"
#include "pack.h"
#include "human.h"
#include "explorer.h"
#include "warrior.h"
#include "bug.h"
#include "hornet.h"
#include "killerant.h"
#include "spider.h"
#include "barbarian.h"
using namespace std;
using namespace GameSpace;

int main(){
	
	//PlayerClass* h1, h2, k1, k2, s1, s2, w1, w2, e1, e2;
	
	Hornet h1("h1");
	Hornet h2("h2");
	
	KillerAnt k1("k1");
	KillerAnt k2("k2");
	
	Spider s1("s1");
	Spider s2("s2");
	
	Warrior w1("w1");
	Warrior w2("w2");
	
	Explorer e1("e1");
	Explorer e2("e2");
	
	Barbarian b1("b1");
	Barbarian b2("b2");
	
	cout << "Making all active.." << endl << endl;
	h1.MakeActive();
	h2.MakeActive();
	s1.MakeActive();
	s2.MakeActive();
	k1.MakeActive();
	k2.MakeActive();
	e1.MakeActive();
	e2.MakeActive();
	w1.MakeActive();
	w2.MakeActive();
	b1.MakeActive();
	b2.MakeActive();
	
	cout << "********Enemy Testing*********" << endl << endl;
	cout << "Hornet to Barbarian: " << h1.IsMyEnemy(&b1) << endl;
	cout << "Hornet to Hornet: " << h1.IsMyEnemy(&h2) << endl;
	cout << "Hornet to KillerAnt: " << h1.IsMyEnemy(&k1) << endl;
	cout << "Hornet to Spider: " << h1.IsMyEnemy(&s1) << endl;
	cout << "Hornet to Warrior: " << h1.IsMyEnemy(&w1) << endl;
	cout << "Hornet to Explorer: " << h1.IsMyEnemy(&e1) << endl << endl;
	
	cout << "KillerAnt to Barbarian: " << k1.IsMyEnemy(&b1) << endl;
	cout << "KillerAnt to KillerAnt: " << k1.IsMyEnemy(&k2) << endl;
	cout << "KillerAnt to Hornet: " << k1.IsMyEnemy(&h1) << endl;
	cout << "KillerAnt to Spider: " << k1.IsMyEnemy(&s1) << endl;
	cout << "KillerAnt to Warrior: " << k1.IsMyEnemy(&w1) << endl;
	cout << "KillerAnt to Explorer: " << k1.IsMyEnemy(&e1) << endl << endl;
	
	cout << "Spider to Barbarian: " << s1.IsMyEnemy(&b1) << endl;
	cout << "Spider to Spider: " << s1.IsMyEnemy(&s2) << endl;
	cout << "Spider to Hornet: " << s1.IsMyEnemy(&h1) << endl;
	cout << "Spider to KillerAnt: " << s1.IsMyEnemy(&k1) << endl;
	cout << "Spider to Warrior: " << s1.IsMyEnemy(&w1) << endl;
	cout << "Spider to Explorer: " << s1.IsMyEnemy(&e1) << endl << endl;
	
	cout << "Warrior to Barbarian: " << w1.IsMyEnemy(&b1) << endl;
	cout << "Warrior to Warrior: " << w1.IsMyEnemy(&w2) << endl;
	cout << "Warrior to Explorer: " << w1.IsMyEnemy(&e2) << endl;
	cout << "Warrior to Hornet: " << w1.IsMyEnemy(&h2) << endl;
	cout << "Warrior to Spider: " << w1.IsMyEnemy(&s2) << endl;
	cout << "Warrior to KillerAnt: " << w1.IsMyEnemy(&k2) << endl << endl;
	
	cout << "Explorer to Barbarian: " << e1.IsMyEnemy(&b1) << endl;
	cout << "Explorer to Explorer: " << e1.IsMyEnemy(&e2) << endl;
	cout << "Explorer to Warrior: " << e1.IsMyEnemy(&w2) << endl;
	cout << "Explorer to Hornet: " << e1.IsMyEnemy(&h2) << endl;
	cout << "Explorer to Spider: " << e1.IsMyEnemy(&s2) << endl;
	cout << "Explorer to KillerAnt: " << e1.IsMyEnemy(&k2) << endl << endl;
	
	
	cout << "Barbarian to Barbarian: " << b1.IsMyEnemy(&b2) << endl;
	cout << "Barbarian to Itself: " << b1.IsMyEnemy(&b1) << endl;
	cout << "Barbarian to Explorer: " << b1.IsMyEnemy(&e1) << endl;
	cout << "Barbarian to Warrior: " << b1.IsMyEnemy(&w1) << endl;
	cout << "Barbarian to Hornet: " << b1.IsMyEnemy(&h1) << endl;
	cout << "Barbarian to KillerAnt: " << b1.IsMyEnemy(&k1) << endl;
	cout << "Barbarian to Spider: " << b1.IsMyEnemy(&s1) << endl << endl;
/*	
	
	cout << "*************Output Testing************" << endl << endl;
	h1.Write(cout);
	//cout << h1 << endl;
	
	k1.Write(cout);
	//cout << k1 << endl;	
	
	s1.Write(cout);
	//cout << s1 << endl;
	
	w1.Write(cout);
	//cout << w1 << endl;
	
	e1.Write(cout);
	//cout << e1 << endl << endl;
	
	cout << "*************Weapon Grabbing*********" << endl << endl;
	cout << "Axe, Mace and Sword being created..." << endl;
	//Weapon mace("Mace");
	//Weapon axe("Axe");
	//Weapon sword("Sword");
	Weapon* mace = new Weapon("Mace");
	Weapon* axe = new Weapon("Axe");;
	Weapon* sword = new Weapon("Sword");
	
	cout << "\nW1 grabbing axe and mace" << endl;
	w1.GrabWeapon(axe);
	w1.GrabWeapon(mace);
	
	cout << "E1 grabbing just a sword" << endl;
	e1.GrabWeapon(sword);
	
	cout << endl;
	
	cout << "Does w1 have weapon?: " << w1.HasWeapon() << endl;
	w1.Write(cout);
	e1.Write(cout);
	
	cout << endl;
	cout << w1.WeaponName() << endl;
	cout << "Warrior wants to hold the axe instead...\n";
	w1.ChangeWeapon("Axe");
	cout << w1.WeaponName() << endl << endl;
	w1.Write(cout);
	
	vector<string> myVec = w1.Pack();
	int length = myVec.size();
	for (int i = 0; i < length; ++i){
		cout << myVec[i] << " ";
	}
*/	
	
	
/*
	for (int i = 0; i < 10; ++i){
		cout << e1.Impact() << " ";
		cout << e1.IsAlive() << endl;
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < 10; ++i){
		cout << h1.Impact() << " ";
		cout << h1.IsAlive() << endl;
	}	
	
	for (int i = 0; i < 10; ++i){
		cout << e1.CriticalWound() << " ";
		cout << e1.IsAlive() << endl;
	}
	
	cout << endl << endl;
	
	for (int i = 0; i < 10; ++i){
		cout << h1.CriticalWound() << " ";
		cout << h1.IsAlive() << endl;
	}	
	
*/	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}