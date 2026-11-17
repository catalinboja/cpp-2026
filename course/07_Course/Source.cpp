#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Building {
	const int id = 0;
	string* tenants = nullptr;
	int noOfTenants = 0;
	int noOfFloors = 0;
	bool isResidential = false;
	static int NO_RESIDENTIAL_BUILDINGS;
public:

	void setTenants(string* tenants, int no) {
		if (tenants == nullptr) {
			throw "Wrong value";
		}

		delete[] this->tenants;
		this->tenants = new string[no];
		for (int i = 0; i < no; i++) {
			this->tenants[i] = tenants[i];
		}
		this->noOfTenants = no;

	}
	//the part after : is named constructor initialisation list
	Building(int receivedId, 
		string* tenants, 
		int no, 
		int noOfFloors, 
		bool isResidential) 
		: id(receivedId), noOfFloors(no), isResidential(isResidential) 
	{

		//this->id = id;
		this->setTenants(tenants, no);
		//this->noOfFloors = noOfFloors;
		//this->isResidential = isResidential;
		if (isResidential)
			Building::NO_RESIDENTIAL_BUILDINGS += 1;
	}

	~Building() {
		delete[] this->tenants;
		this->tenants = nullptr;
		if (this->isResidential)
			Building::NO_RESIDENTIAL_BUILDINGS -= 1;
	}

	//copy constructor
	Building(const Building& b): id(b.id) {

		cout << endl << "Copy ctor";

		//b.noOfFloors = this->noOfFloors;
		this->setTenants(b.tenants, b.noOfTenants);
		this->isResidential = b.isResidential;
		this->noOfFloors = b.noOfFloors;
		if (this->isResidential)
			Building::NO_RESIDENTIAL_BUILDINGS += 1;
	}

	//move constructor
	Building(Building&& b) {

		this->setTenants(b.tenants, b.noOfTenants);
		this->isResidential = b.isResidential;
		this->noOfFloors = b.noOfFloors;
		if (this->isResidential)
			Building::NO_RESIDENTIAL_BUILDINGS += 1;

		delete[] b.tenants;
		b.tenants = nullptr;
		b.noOfTenants = 0;
	}

};

//requires COPY CTOR
void doNothing(Building x) {

}


//DOES NOT
void doNothing2(Building& x) {

}

//DOES NOT
void doNothing3(Building* x) {

}

Building doABuilding() {
	string tenants[] = { "John", "Alice", "Bob" };
	Building b(1, tenants, 3, 7, false);
	return b;
}


int Building::NO_RESIDENTIAL_BUILDINGS = 0;

int main() {
	string tenants[] = { "John", "Alice", "Bob" };
	Building b(1, tenants, 3, 7, false);

	Building* pB = new Building(2, tenants, 3, 7, false);
	delete pB;

	doNothing(b);

	//call the copy ctor
	Building clone = b;
	Building anotherClone(b);



}