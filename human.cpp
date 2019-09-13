//Author: Neil Noyes

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
using namespace std;
using namespace GameSpace;


Human::~Human()
{

	delete heldWpn;
	heldWpn = NULL;
	delete pack;
	
}

void Human::CopyToHuman(const Human& h){
	
	if (h.heldWpn){
		heldWpn = new Weapon(*h.heldWpn);
	}
	WpnSkill = h.WpnSkill;

}

Human& Human::operator=(const Human& someHuman){
	
	if (this != &someHuman){
		
		PlayerClass::operator=(someHuman);
		delete heldWpn;
		CopyToHuman(someHuman);
		pack->EmptyPack();
		*pack = *someHuman.pack;
	}
	
	return *this;
}

PackClass* Human::GetPackAddress() const{
	
	return (new PackClass(10*RollPhysDam()));
}

PackClass* Human::CopyPack(const PackClass* p) const{
	
	return (new PackClass(*p));
}

Human::Human(const Human& someHuman):heldWpn(NULL),pack(CopyPack(someHuman.pack)),PlayerClass(someHuman)
{
	CopyToHuman(someHuman);
}

Human::Human(const string inName, const int CONST_STATS[], const int VAR_STATS[]):PlayerClass(inName,
																							  CONST_STATS,
																							  VAR_STATS),
																					pack(GetPackAddress()),
																					heldWpn(NULL)
{

}	

Human::Human():heldWpn(NULL),pack(NULL),PlayerClass("",NULL,NULL)
{
	
}																						  

void Human::Write(ostream& out) const{
	
	
	if(HasWeapon()){
	
		PlayerClass::Write(out);
	
		out << "\t" << WeaponNameAndNum() << "#" << WeaponSkill();
		
		for (map<string,int>::const_iterator it = WpnSkill.begin(); it != WpnSkill.end(); ++it){
			out << "#" << it->first << "#" << it->second;
		}
		out << endl;		
	}	
	else if (!HasWeapon() && !WpnSkill.empty()){
		
		PlayerClass::Write(out);
		
		out << "\t" << "#";
		for (map<string,int>::const_iterator it = WpnSkill.begin(); it != WpnSkill.end(); ++it){
			out << "#" << it->first << "#" << it->second;
		}
		out << endl;		
	}
	else{
		PlayerClass::Write(out);
	}
}

bool Human::IsMyEnemy(const PlayerClass* p) const{
	static bool beenHere = false;
	bool enemy = false;
	
	const Human* h = dynamic_cast<const Human*>(p);
	
	if (h == NULL && p != NULL){
		enemy = true;
	}
	else if (p != NULL && !beenHere){
		beenHere = true;
		enemy = p->IsMyEnemy(this);
	}
	else if (beenHere){
		beenHere = false;
	}
	else{
		enemy = false;
	}

	return (enemy);
}

int Human::HitDamage() const{
	
	int dmg = 0;
	
	if (IsActive()){
		
		if (heldWpn){
			
			
			string wpnToFind = heldWpn->Name();
			transform(wpnToFind.begin(),wpnToFind.end(),wpnToFind.begin(), ::toupper);
			map<string,int>::const_iterator iter = WpnSkill.find(wpnToFind);
			
			int wSkill = 0;
			
			if (iter != WpnSkill.end()){
				wSkill = iter->second;
			}
			
			int wpnRoll = static_cast<const Weapon*>(heldWpn)->RollWeaponDamage(PlayerClass::Name());
			dmg = wSkill + wpnRoll;
		}
		else{
			
			dmg = Power() + RollPhysDam();
		}	
		
	}
	
	return dmg;
}

string Human::WeaponNameAndNum() const{
	
	string wpnNameAndNum;
	
	if (heldWpn){
		wpnNameAndNum = heldWpn->NameAndNum();
	}
	else{
		wpnNameAndNum = "";
	}
	
	return wpnNameAndNum;
}

string Human::WeaponName() const{
	
	string wpn;
	
	if (heldWpn){
		wpn = heldWpn->Name();
	}
	else{
		wpn = "";
	}
	
	return wpn;
}

bool Human::HasWeapon() const{
	
	return heldWpn;
}

Weapon* Human::GrabWeapon(Weapon* weapon){
	
	if (!weapon)
		throw INVALID_WPN;
	
	
	Weapon* temp;
	

	if(IsActive()){

		if (heldWpn){  //if we are holind a weapon
			
			if (pack->AddWeapon(heldWpn) == false){	//if we cant add heldWpn to pack, then send it back
				//heldWpn = NULL;
				temp = DropWeapon();
			}	
			else{ //if we can add it and are holding something
				temp = NULL;	
				heldWpn = NULL;
			}
 					  					
		}
		else{	

			temp = NULL;		
		}
	
		heldWpn = (weapon);
	
	
		string nameToInsert = weapon->Name();
		transform(nameToInsert.begin(),nameToInsert.end(),nameToInsert.begin(), ::toupper);
		
		if (Human::WpnSkill.find(nameToInsert) == Human::WpnSkill.end()){
			Human::WpnSkill.insert(pair<string,int>(nameToInsert,1));
		}

	}
	else{
		
		temp = weapon;		
	}
	
	return temp;	
}

Weapon* Human::DropWeapon(){
	
	Weapon* temp = NULL;
	
	
	if (IsActive() && HasWeapon()){
		
		if(heldWpn){
			
			string wpnToRemove = heldWpn->Name();	
			pack->RemoveWeapon(wpnToRemove);			
			temp = heldWpn;
			heldWpn = NULL;
		}	
	}
	
	return temp;
}

int Human::Impact() const{
	
	int imp = 0;
	
	if (IsActive()){
		
		int rollVal = RollImpact();
		
		if (heldWpn){	
			
			int wpnPow = heldWpn->Power();
		
			
			if(LookupImpact(wpnPow,rollVal) == PlayerClass::W){
				imp = -1;
			}
			else{
					
				imp = LookupImpact(wpnPow,rollVal);
			}
			
		}
		else{
			
			if (Power() < 2){
				imp = 0;
			}
			else{
				imp = LookupImpact(Power(),rollVal);
			}			
		}		
	}
	
	return imp;
}

int Human::WeaponSkill() const{
	
	int heldSkill = 0;
	
	if (heldWpn){
		
		string nameToFind = heldWpn->Name();
		transform(nameToFind.begin(),nameToFind.end(),nameToFind.begin(), ::toupper);
		
		if(Human::WpnSkill.find(nameToFind) != Human::WpnSkill.end()){
			
			heldSkill = Human::WpnSkill.find(nameToFind)->second;
		}
	}
	
	return heldSkill;
}

bool Human::ImprovedSkill(int improvement){
	
	bool done = false;
	
	if (IsActive() && improvement > 0 && heldWpn){
		
		string nameToFind = heldWpn->Name();
		transform(nameToFind.begin(),nameToFind.end(),nameToFind.begin(), ::toupper);
		
		if(Human::WpnSkill.find(nameToFind) != Human::WpnSkill.end()){ 
		
			Human::WpnSkill.find(nameToFind)->second += improvement;
			
		}
		done = true;
	}
	
	return done;
}

string Human::TypeStr() const{
	
}

Weapon* Human::ChangeWeapon(string weaponName){
	
	Weapon* ret_w = NULL;
	Weapon* temp = NULL;
	
	if (IsActive() && heldWpn){
		string ourWep = heldWpn->Name();
		transform(ourWep.begin(), ourWep.end(), ourWep.begin(), ::toupper);
		transform(weaponName.begin(), weaponName.end(), weaponName.begin(), ::toupper);
		
		if (ourWep != weaponName && pack->InPack(weaponName)){ //if in pack and not the same name as one we holdi
			
			temp = (pack->RemoveWeapon(weaponName));
			
			if (pack->AddWeapon(heldWpn)){//if we can put held wpn in pack then add it					
				ret_w = NULL;
			}
			else{
				ret_w = heldWpn; //if we cant fit it then return it
			}
			
			heldWpn = temp;			
		}

	}
	
	return ret_w;	
}

vector<string> Human::Pack() const{
	return pack->PackInventory();
}