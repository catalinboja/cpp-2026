#include <iostream>
#include <string>

using namespace std;


enum ParkingType { OUTDOOR, COVERED, UNDERGROUND };

class ParkingLot {
	string name = "";
	bool* occupiedSpaces = nullptr;
	int noSpaces = 0;
	float hourlyRate = 0;
	ParkingType type = ParkingType::OUTDOOR;
	static int TOTAL_LOTS;
	const static float MIN_FEE;
public:
	string getName() {
		return this->name;
	}

	bool* getSpaces() {
		bool* copy = new bool[this->noSpaces];
		for (int i = 0; i < this->noSpaces; i++) {
			copy[i] = this->occupiedSpaces[i];
		}
		return copy;
	}

	void setSpaces(bool* spaces, int noSpaces) {
		if (spaces == nullptr || noSpaces < 1) {
			throw "Wrong data";
		}

		delete[] this->occupiedSpaces;
		this->occupiedSpaces = new bool[noSpaces];
		for (int i = 0; i < noSpaces; i++) {
			this->occupiedSpaces[i] = spaces[i];
		}
		this->noSpaces = noSpaces;
	}

	int getNoOfSpaces() {
		return this->noSpaces;
	}

	ParkingLot(string name, bool* spaces,
		int noSpaces, float fee) {
		if (name.size() < 4) {
			throw "Invalid name";
		}
		if (fee <= 0) {
			throw "Invalid fee";
		}
		this->name = name;
		this->setSpaces(spaces, noSpaces);
		this->hourlyRate = fee;
		this->type = ParkingType::OUTDOOR;
	}

	ParkingLot(string name, bool* spaces,
		int noSpaces, float fee, ParkingType type) {
		if (name.size() < 4) {
			throw "Invalid name";
		}
		if (fee <= 0) {
			throw "Invalid fee";
		}

		if (type == ParkingType::UNDERGROUND && 
			fee < MIN_FEE) {
			throw "Wrong fee for Underground";
		}

		this->name = name;
		this->setSpaces(spaces, noSpaces);
		this->hourlyRate = fee;
		this->type = type;
	}

	ParkingLot() {

	}

	void print() {
		cout << endl << "Name: " << this->name;
		cout << endl << "Fee: " << this->hourlyRate;
		cout << endl << "No of places: " << this->noSpaces;
		cout << endl << "Spaces: ";
		for (int i = 0; i < this->noSpaces; i++) {
			cout << " " << this->occupiedSpaces[i];
		}
		cout << endl << "Type: " << this->type;

	}

	~ParkingLot() {
		delete[] this->occupiedSpaces;
		this->occupiedSpaces == nullptr;
	}

	float getTotalIncome() {
		int noOccupiedSpaces = 0;
		for (int i = 0; i < this->noSpaces; i++) {
			if (this->occupiedSpaces[i] == true) {
				noOccupiedSpaces += 1;
			}
		}
		return noOccupiedSpaces * this->hourlyRate;
	}

	float getTotalCost(int totalHours, bool hasSubscription) {
		if (totalHours < 0) {
			throw "Negative hours";
		}
		if (totalHours == 0) {
			return 0;
		}

		if (this->type == ParkingType::OUTDOOR) {
			totalHours -= 1;
		}

		float totalCost = totalHours * this->hourlyRate;
		
		if (this->type == ParkingType::COVERED &&
			totalHours >= 8) {
			totalCost *= 0.9;
		}

		if (hasSubscription) {
			totalCost *= 0.8;
		}

		if (type == ParkingType::UNDERGROUND) {
			totalCost += 5;
		}


		return totalCost;
	}

	//copy ctor
	ParkingLot(const ParkingLot& p)
		: hourlyRate(p.hourlyRate), name(p.name), 
		type(p.type) {
		this->setSpaces(p.occupiedSpaces, p.noSpaces);
	}

	//move ctor
	ParkingLot(ParkingLot&& p)
	:hourlyRate(p.hourlyRate), name(p.name), type(p.type){
		this->occupiedSpaces = p.occupiedSpaces;
		this->noSpaces = p.noSpaces;
		p.occupiedSpaces = nullptr;
		p.noSpaces = 0;
	}

	//overload =
	void operator=(const ParkingLot& p) {
		if (this == &p) {
			return;
		}
		this->name = p.name;
		this->type = p.type;
		this->hourlyRate = p.hourlyRate;
		this->setSpaces(p.occupiedSpaces, p.noSpaces);
	}

	//overload ++ post
	ParkingLot operator++(int) {
		ParkingLot copy = *this;
		this->hourlyRate += 1;
		return copy;
	}
	//overload ++ pre
	ParkingLot operator++() {
		this->hourlyRate += 1;
		return *this;
	}
};

int ParkingLot::TOTAL_LOTS = 0;
const float ParkingLot::MIN_FEE = 10;

int main() {
	ParkingLot parking;
	cout << endl << "Parking name: " <<
		parking.getName();
	bool places[] = { true, true, false, false, true };
	parking.setSpaces(places, 5);

	bool* existingPlaces = parking.getSpaces();
	int noSpaces = parking.getNoOfSpaces();
	cout << endl << "Parking spaces: ";
	for (int i = 0; i < noSpaces; i++) {
		cout << " " << existingPlaces[i];
	}

	ParkingLot parkingRomana("Romana", places, 5, 5);

	parkingRomana.print();
	parking.print();

	ParkingLot parkingVictoriei("Victorie", places, 
		5, 15, ParkingType::UNDERGROUND);
	parkingVictoriei.print();

	ParkingLot* p = new ParkingLot();
	delete p;

	{
		ParkingLot p2;
	}

	cout << endl << "Total revenue: " 
		<< parkingVictoriei.getTotalIncome();

	cout << endl << "Total cost: "
		<< parkingVictoriei.getTotalCost(12, true);

	ParkingLot victoriei = parkingVictoriei;
	ParkingLot romana(parkingRomana);

	victoriei.print();

	ParkingLot newVictoriei = std::move(victoriei);
	ParkingLot newRomana(std::move(romana));

	cout << endl << "______________________";
	victoriei.print();
	newVictoriei.print();

	newVictoriei = newRomana;
	newVictoriei = newVictoriei;

	newVictoriei++; //increment the hourly rate
	++newVictoriei;
}