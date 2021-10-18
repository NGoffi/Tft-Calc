// holds values that compose a tft item
class Item {

private:

public:

	std::string name; // item name

	float ad;	// attack damage
	float ap;	// ability power
	float pdr;	// physical damage reduction
	float mdr;	// magic damage reduction
	float aps;	// attacks per second
	float hp;	// health points
	float smp;	// starting mana points
	float csc;	// critical strike chance

	Item(float ad = 0, float ap = 0, float pdr = 0, float mdr = 0, float aps = 0, float hp = 0, float smp = 0, float csc = 0); // inital values for overloading

	void Show(); // displays information about items as a string

	// setters
	void SetAD(float ad_new);
	void SetAP(float ap_new);
	void SetPDR(float pdr_new);
	void SetMDR(float mdr_new);
	void SetAPS(float aps_new);
	void SetHP(float hp_new);
	void SetSMP(float smp_new);
	void SetCSC(float csc_new);
	
	void SetNAME(std::string name_new);
};