#include<string>
#include<iostream>

#include "Item.h"

using namespace std;

// Uses constructor to initiate values for item class 
Item::Item(float ad, float ap, float pdr, float mdr, float aps, float hp, float smp, float csc) {
	this->ad = ad;
	this->ap = ap;
	this->pdr = pdr;
	this->mdr = mdr;
	this->aps = aps;
	this->hp = hp;
	this->smp = smp;
	this->csc = csc;
}

// displays information about items as a string
void Item::Show() {
	//cout << name << "AD:" + to_string(ad) + " | " + "AP:" + to_string(ap) + " | " + "ARMOUR:" + to_string(pdr) + " | " + "MAGIC RESIST:" + to_string(mdr) + " | " + "APS:" + to_string(aps) + " | " + "HP:" + to_string(hp) + " | " + "MANA POOL:" + to_string(smp) + " | " + "CRITICAL STRIKE CHANCE:" + to_string(csc) + " | " << endl;
	cout << " name: " << name <<" attack danage: " << ad << " armor:  " << pdr << " attack speed:  " << aps << " ability power: " << ap << " magic damage reduction: " << mdr << " health: " << hp << " mana: " << smp << " critical strike chance: " << csc << endl << endl;
}

// Setters
void Item::SetNAME(std::string name_new) {
	name = name_new;
}

void Item::SetAD(float ad_new) {
	ad = ad_new;
}

void Item::SetAP(float ap_new) {
	ap = ap_new;
}

void Item::SetPDR(float pdr_new) {
	pdr = pdr_new;
}

void Item::SetMDR(float mdr_new) {
	mdr = mdr_new;
}

void Item::SetAPS(float aps_new) {
	aps = aps_new;
}

void Item::SetHP(float hp_new) {
	hp = hp_new;
}

void Item::SetSMP(float smp_new) {
	smp = smp_new;
}

void Item::SetCSC(float csc_new) {
	csc = csc_new;
}