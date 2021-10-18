#include<string>
#include<iostream>
#include<iomanip>

#include "Unit.h"

using namespace std;

// uses constructor to initiate values for unit class
Unit::Unit(float ad, float ap, float pdr, float mdr, float aps, float hp, float smp, float mmp, float mpa, float sd, float crd, float csc, bool can_scrit, int items_held) {
	this->ad = ad;
	this->ap = ap;
	this->pdr = pdr;
	this->mdr = mdr;
	this->aps = aps;
	this->hp = hp;
	this->smp = smp;
	this->mmp = mmp;
	this->mpa = mpa;
	this->sd = sd;
	this->crd = crd;
	this->csc = csc;
	this->can_scrit = can_scrit;
}

// Setters
void Unit::SetNAME(std::string name_new) {
	name = name_new;
}

void Unit::SetAD(float ad_new) {
	ad = ad_new;
}

void Unit::SetAP(float ap_new) {
	ap = ap_new;
}

void Unit::SetPDR(float pdr_new) {
	pdr = pdr_new;
}

void Unit::SetMDR(float mdr_new) {
	mdr = mdr_new;
}

void Unit::SetAPS(float aps_new) {
	aps = aps_new;
}

void Unit::SetHP(float hp_new) {
	hp = hp_new;
}

void Unit::SetSMP(float smp_new) {
	smp = smp_new;
}

void Unit::SetMMP(float mmp_new) {
	mmp = mmp_new;
}

void Unit::SetCRD(float crd_new) {
	crd = crd_new;
}

void Unit::SetCSC(float csc_new) {
	csc = csc_new;
}

// attempts to add an item to the units item list
void Unit::Set_Item_List(Item item) {
	if (item_list.size() < 3) {
		item_list.push_back(item);
	}
	else {
		cout << "WARNING: " << name << " has maximum amount of items(3), did not add: " << item.name << endl << endl;
	}
}

// displays the items equipped to the unit
void Unit::Show_Item_List() {
	cout << name << " items: " << endl;
	for (Item i : item_list) {
		i.Show();
	}
}

// calculates the units auto attack damage per second, assuming no spell casts occured
float Unit::DPS() {
	float new_ad = ad;
	float new_aps = aps;
	float new_csc = csc;

	for (Item i : item_list) {
		new_ad += i.ad;
		new_aps += i.aps;
		new_csc += i.csc;
	}
	cout << name << ": base ad: " << ad << ", base aps: " << aps << endl << endl;
	cout << name << ": total ad " << new_ad << ", total aps " << new_aps << endl << endl;
	return new_ad * new_aps * (1+new_csc);
}

// calculates the units cast time from an empty mana pool assuming no damage taken
float Unit::CTS() const {
	return mmp / (mpa * aps);
}

// calculates the number of attacks required to cast from units starting mana pool
int Unit::APC() const {
	float m = smp; // mana variable, diferentiate between starting and actual
	int i = 0; // counter
	while (mmp > m) {
		m += mpa;
		i += 1;
	}
	return i;
}

// calculates spell damage, for critical damage assumes average value
float Unit::TSD() {
	float c = 1; // holds critical strike damage multipler
	float s = 1; // holds critical strike chance
	if (can_scrit == 1) {
		c = crd;
		s = csc;
		return sd * (1 + (c * s)) * (ap / 100);
	}
	return sd * (ap / 100);
}

// calculates the units physical damage reduction as a percentage
float Unit::Phys_Reduc() {
	float new_pdr = pdr;
	for (Item i : item_list) {
		new_pdr += i.pdr;
	}
	if (pdr >= 0) {
		cout << name << " physical reduction: " << (100 / (100 + new_pdr)) << endl;
		return (100 / (100 + new_pdr));
	}
	cout << "physical reduction: " << (2 - (100 / (100 - new_pdr))) << endl;
	return (2 - (100 / (100 - new_pdr)));
}

// calculates the units magical damage reduction as a percentage
float Unit::Magic_Reduc() {
	float new_mdr = mdr;
	for (Item i : item_list) {
		new_mdr += i.mdr;
	}
	if (mdr >= 0) {
		cout << "magic reduction: " << (100 / (100 + new_mdr)) << endl;
		return (100 / (100 + new_mdr));
	}
	cout << "magic reduction: " << (2 - (100 / (100 - new_mdr))) << endl;
	return (2 - (100 / (100 - new_mdr)));
}

// shows how long a basic attack fight between two units lasts and who wins
string Unit::Basic_Fight(Unit U) {
	float Unit_1 = (hp / (U.DPS() * Phys_Reduc()));
	float Unit_2 = (U.hp / (DPS() * U.Phys_Reduc()));

	if (Unit_1 > Unit_2) {
		cout << name <<": " << Unit_1 << " | " << U.name << ": " << Unit_2 << endl << "The winner of the fight is: " << name << endl << endl;
		return name;
	}
	if (Unit_1 == Unit_2) {
		cout << name << ": " << Unit_1 << " | " << U.name << ": " << Unit_2 << endl << "Units are even- Likely identical" << endl;
		return  "null";
	}
	cout << name << ": " << Unit_1 << " | " << U.name << ": " << Unit_2 << endl << "The winner of the fight is: " << U.name << endl << endl;
	return U.name;
}

// displays information about the unit as a string
void Unit::Show() {
	cout << setprecision(3) << fixed << name << " AD:" << (ad) << " | " << "AP:" << (ap) << " | " << "ARMOUR:" << (pdr) << " | " << "MAGIC RESIST:" << (mdr) << " | " << "APS:" << (aps) << " | " << "HP:" << (hp) << " | " << "MANA POOL:" << (smp) << "/" << (mmp) << " | " << "SPELL DAMAGE:" << (sd) << " | " << "CRITICAL DAMAGE:" << (crd) << " | " << "CRITICAL STRIKE CHANCE:" << (csc) << " | " << "SPELL CRIT:" << (can_scrit) << " | " << "AMOUNT OF ITEMS: " << endl << endl;
}
