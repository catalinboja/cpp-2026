#include <iostream>
#include <string>
#include <string.h>

using namespace std;

enum BusType {ELECTRIC, DIESEL, HYBRID};

class Bus {
	char* destination = nullptr;
	float ticketPrice = 0.0;
	int number = 0;
	BusType type = BusType::DIESEL;

	static int ELECTRIC_BUSES_COUNTER;


public:

	static const int MIN_DESTINATION_SIZE = 5;

	char* getDestination() {
		if (this->destination != nullptr) {
			char* copy = new char[strlen(this->destination) + 1];
			strcpy_s(copy, strlen(this->destination) + 1, this->destination);
			return copy;
		}
		return nullptr;
	}

	void setDestination(const char* newDestination) {

		if (newDestination == nullptr || strlen(newDestination) < Bus::MIN_DESTINATION_SIZE) {
			throw "Wrong destination";
		}

		delete[] this->destination;
		this->destination = new char[strlen(newDestination) + 1];
		strcpy_s(this->destination,
			strlen(newDestination) + 1, newDestination);

	}

	~Bus() {
		cout << endl << "BUS Destructor";
		delete[] this->destination;
		this->destination = nullptr;
	}

};

int Bus::ELECTRIC_BUSES_COUNTER = 0;

int main() {

	Bus bus;
	bus.setDestination("Ploiesti");
	if(bus.getDestination() != nullptr)
		cout << endl << "Destination: " << bus.getDestination();

	Bus* pBus = new Bus();
	delete pBus;

	{
		Bus temp;
	}


	cout << endl << "The end";
}