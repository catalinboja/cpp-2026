#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//option 1
enum LaboratoryType {ROBOTICS = 10, AI = 20, MULTIMEDIA, CLASSIC};

class Laboratory {

	//set default values for attributes
private:
	char* building = nullptr;
	string name = "";
	int noOfSeats = 0;
	bool isAvailable = false;


	//option 2 - Don't
	//enum LaboratoryType {ROBOTICS = 10, AI = 20, MULTIMEDIA, CLASSIC};

	LaboratoryType type = LaboratoryType::CLASSIC;


	//DON't
	//int type; // 0 - robotics, 1 - classic
	//string type; // "robotics", "ROBOTICS|", "Sobotics", "multimedia"

public:
	int getNoOfSeats() {
		return this->noOfSeats;
	}

	void setNoOfSeats(int noOfSeats) {
		//shadowing
		//noOfSeats = noOfSeats;

		if (noOfSeats <= 0) {
			throw "Wrong number of seats";
		}
		this->noOfSeats = noOfSeats;
	}

	char* getBuilding() {
		//DON'T do this
		//shallow copy
		//return this->building;

		//deep copy
		// + 1 for \0

		if(this->building != nullptr){
			char* copy = new char[strlen(this->building) + 1];
			int maximumChars = 50;
			strcpy_s(copy, maximumChars,this->building);

			return copy;
		}
		else {
			return nullptr;
		}
	}

	void setBuilding(const char* buildingName) {
		//don't
		//this->building = buildingName;

		//at least 5 chars
		if (buildingName == nullptr || strlen(buildingName) < 5)
		{
			throw "Name too short";
		}

		//deep copy
		this->building = new char[strlen(buildingName) + 1];
		int maxSize = 50;
		strcpy_s(this->building, maxSize, buildingName);
	}

	//constructors
	//default
	Laboratory() {

	}

	Laboratory(
		const char* building,
		string name,
		int noOfSeats,
		bool isAvailable,
		LaboratoryType type) {
		this->setBuilding(building);
		this->setNoOfSeats(noOfSeats);
		this->isAvailable = isAvailable;
		this->type = type;
		this->name = name;
	}

};

//option 3 - Don't
//enum LaboratoryType {ROBOTICS = 10, AI = 20, MULTIMEDIA, CLASSIC};


int main() {

	LaboratoryType type;

	//use the class default constructor
	Laboratory laboratory;

	//laboratory.name = "2016";

	//laboratory.setNoOfSeats(-29);

	cout << endl << "No of seats: " 
		<< laboratory.getNoOfSeats();
	laboratory.setNoOfSeats(29);
	cout << endl << "No of seats: "
		<< laboratory.getNoOfSeats();

	if (laboratory.getBuilding() != nullptr) {
		cout << endl << "Building name: "
			<< laboratory.getBuilding();
	}

	laboratory.setBuilding("Madgearu");
	if (laboratory.getBuilding() != nullptr) {
		cout << endl << "Building name: "
			<< laboratory.getBuilding();
	}

	Laboratory s2016("Madgearu", "2016", 
		30, true, LaboratoryType::ROBOTICS);

	return 0;
}