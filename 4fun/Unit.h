#include<vector>

#include "Item.h"

// holds values that compose a tft unit
class Unit {
private:

	std::string name; // unit name

	float ad;	// attack damage
	float ap;	// ability power
	float pdr;	// physical damage reduction
	float mdr;	// magic damage reduction
	float aps;	// attacks per second
	float hp;	// health points
	float smp;	// starting mana points
	float mmp;	// maximum mana pool
	float mpa;	// mana per attack
	float sd;	// spell damage
	float crd;	// critical damage
	float csc;	// critical strike chance

	std::vector<Item> item_list; //stores items

	bool can_scrit; // can units spells critically strike

public:
	// inital values for overloading
	Unit(float ad = 0, float ap = 0, float pdr = 0, float mdr = 0, float aps = 0, float hp = 0, float smp = 0, float mmp = 0, float mpa = 10, float sd = 0, float crd = 0.3, float csc = 0.25, bool can_scrit = false, int items_held = 0); 
	
	float DPS();		// Damage per second
	float CTS() const;		// Cast time per second
	float TSD();			// total spell damage from all sources
	float Magic_Reduc(); // Magic damage reduction for a unit
	float Phys_Reduc(); // Physical damage reduction for a unit
	
	int APC() const;		// Attacks per cast (from starting mana)
	
	void Show();			// displays information about the unit as a string

	// setters
	void SetAD(float ad_new);
	void SetAP(float ap_new);
	void SetPDR(float pdr_new);
	void SetMDR(float mdr_new);
	void SetAPS(float aps_new);
	void SetHP(float hp_new);
	void SetSMP(float smp_new);
	void SetMMP(float mmp_new);
	void SetCRD(float crd_new);
	void SetCSC(float csc_new);
	
	void Set_Item_List(Item item);
	void Show_Item_List();

	void SetNAME(std::string name_new);

	std::string Basic_Fight(Unit U);

};