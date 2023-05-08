// Noah Goffin Fun TFT Project
// Trying to calculate anything I can using in game value

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

#include <nlohmann/json.hpp>

#include "Unit.h"

using namespace std;
using namespace nlohmann;

int main() {
	
	// maps champions in the Unit class
	map<string, Unit> champion;
	string name;

	// maps items in the Item class
	map<string, Item> item;
	string iname;

	// opens and parses items and units from the Tft.json file
	ifstream file("Resources/Tftnew.json");
	json j;
	file >> j;

	for (json& o : j["items"]) {

		float ad = 0;
		float ap = 0;	
		float pdr = 0;	
		float mdr = 0;	
		float aps = 0;	
		float hp = 0;	
		float smp = 0;	
		float csc = 0;	

		json& effects = o["effects"];
		name = to_string(o["name"]);
		name = name.substr(1, name.size() - 2);

		if (to_string(effects["Armor"]) != "null") {
			pdr = effects["Armor"];
			item[name].SetPDR(pdr);
		}

		if (to_string(effects["AS"]) != "null") {
			aps = effects["AS"];
			item[name].SetAPS(aps);
		}

		if (to_string(effects["AD"]) != "null") {
			ad = effects["AD"];
			item[name].SetAD(ad);
		}

		if (to_string(effects["Health"]) != "null") {
			hp = effects["Health"];
			item[name].SetHP(hp);
		}

		if (to_string(effects["AP"]) != "null") {
			ap = effects["AP"];
			item[name].SetAP(ap);
		}

		if (to_string(effects["Mana"]) != "null") {
			smp = effects["Mana"];
			item[name].SetSMP(smp);
		}

		if (to_string(effects["MagicResist"]) != "null") {
			mdr = effects["MagicResist"];
			item[name].SetMDR(mdr);
		}

		if (to_string(effects["CritChance"]) != "null") {
			csc = effects["CritChance"];
			item[name].SetCSC(csc);
		}

		item[name].SetNAME(name);
		
	}
	cout << "finished parsing items" << endl;
	// parses champion data to get stats
	for (json& o : j["setData"]) {
		for (auto& champ : o["champions"]) {
			
			// initalize floats of champion stat values
			float armor = 0;
			float critChance = 0;
			float attackSpeed = 0;
			float critMultiplier = 0;
			float hp = 0;
			float initialMana = 0;
			float magicResist = 0;
			float mana = 0;
			float damage = 0;

			// creates a name for each unit in Unit class and  maps it
			name = to_string(champ["name"]);
			name = name.substr(1, name.size() - 2);
			//champion[name] = Unit();

			// checks if value points to null, if not assigns to float
			if (champ["stats"]["critChance"] != nullptr) {
				critChance = champ["stats"]["critChance"];
			}
			if (champ["stats"]["damage"] != nullptr) {
				damage = champ["stats"]["damage"];
			}
			if (champ["stats"]["mana"] != nullptr) {
				mana = champ["stats"]["mana"];
			}
			if (champ["stats"]["magicResist"] != nullptr) {
				magicResist = champ["stats"]["magicResist"];
			}
			if (champ["stats"]["initialMana"] != nullptr) {
				initialMana = champ["stats"]["initialMana"];
			}
			if (champ["stats"]["hp"] != nullptr) {
				hp = champ["stats"]["hp"];
			}
			if (champ["stats"]["critMultiplier"] != nullptr) {
				critMultiplier = champ["stats"]["critMultiplier"];
			}
			if (champ["stats"]["armor"] != nullptr) {
				armor = champ["stats"]["armor"];
			}
			if (champ["stats"]["attackSpeed"] != nullptr) {
				attackSpeed = champ["stats"]["attackSpeed"];
			}

			// sets value for particular unit stats
			champion[name].SetPDR(armor);
			champion[name].SetAPS(attackSpeed);
			champion[name].SetCSC(critChance);
			champion[name].SetCRD(critMultiplier);
			champion[name].SetHP(hp);
			champion[name].SetSMP(initialMana);
			champion[name].SetMDR(magicResist);
			champion[name].SetMMP(mana);
			champion[name].SetAD(damage);
			champion[name].SetNAME(name);
		}
		cout << "finished parsing champions" << endl;
	}

	champion["Samira"].Set_Item_List(item["Infinity Edge"]);
	//champion["Zyra"].Set_Item_List(item[""]);
	//champion["Zyra"].Set_Item_List(item["Bramble Vest"]);
	//champion["Udyr"].Set_Item_List(item["Bramble Vest"]);
	//champion["Zyra"].Set_Item_List(item["Chalice of Malice"]);
	//champion["Zyra"].Basic_Fight(champion["Rell"]);

	champion["Samira"].Basic_Fight(champion["Ashe"]);

	return 0;
}