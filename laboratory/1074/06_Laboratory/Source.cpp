#include <iostream>
#include <string>
#include <string.h>

using namespace std;

enum BusType {ELECTRIC, DIESEL, HYBRID};

class BusRoute {
	//char*
	//int* float*
	//string*

	std::string* stations = nullptr;
	int noOfStations = 0;
	float ticketPrice = 0;
	bool isSuspended = false;
	BusType type = BusType::DIESEL;

	static int NO_ELECTRIC_BUSES;

public:

	static const float MIN_TICKET_PRICE;

	string* getStations() {
		if (this->noOfStations > 0) {

			string* copy = new string[this->noOfStations];
			for (int i = 0; i < this->noOfStations; i++) {
				copy[i] = this->stations[i];
			}
			return copy;
		}
		else {
			return nullptr;
		}
	}

	int getNoOfStations() {
		return this->noOfStations;
	}

	void setStations(string* newStations, int noOfStations) {
		if (newStations == nullptr || noOfStations == 0) {
			throw "Wrong input for stations";
		}

		delete[] this->stations;
		this->stations = new string[noOfStations];
		for (int i = 0; i < noOfStations; i++) {
			this->stations[i] = newStations[i];
		}
		this->noOfStations = noOfStations;

	}

	float getTicketPrice() {
		return this->ticketPrice;
	}

	void setTicketPrice(float value) {
		if (value < BusRoute::MIN_TICKET_PRICE) {
			throw "Invalid ticket price";
		}
		this->ticketPrice = value;
	}

	BusRoute(string* stations,
		int noOfStations,
		float price,
		bool isSuspended,
		BusType type) {

		this->setStations(stations, noOfStations);
		this->setTicketPrice(price);
		this->isSuspended = isSuspended;
		this->type = type;

		if (this->type == BusType::ELECTRIC)
			BusRoute::NO_ELECTRIC_BUSES += 1;

	}

	BusRoute() {

	}

	static int getNoOfElectricBuses() {
		return BusRoute::NO_ELECTRIC_BUSES;
	}

	~BusRoute() {

		cout << endl << "Destructor call";

		delete[] this->stations;
		this->stations = nullptr;

		if (this->type == BusType::ELECTRIC)
			BusRoute::NO_ELECTRIC_BUSES -= 1;
	}

};

int BusRoute::NO_ELECTRIC_BUSES = 0;
const float BusRoute::MIN_TICKET_PRICE = 5;

int main() {

	BusRoute busRoute;

	string stations[] = 
	{ "Piata Romana", "Piata Victoriei", "Baneasa" };
	int numbers[] = { 10,23,56,7,1 };

	busRoute.setStations(stations, 3);

	string* busStations = busRoute.getStations();
	int noOfStations = busRoute.getNoOfStations();
	//cout << endl << "Stations: " << busStations;
	for (int i = 0; i < noOfStations; i++) {
		cout << endl << busStations[i];
	}

	//test the destructor
	BusRoute* pb = new BusRoute();
	delete pb;

	{
		BusRoute temp;
	}


	BusRoute bus2(stations, 3, 7, false, BusType::ELECTRIC);

	cout << endl << "Electric Bus routes: " <<
		BusRoute::getNoOfElectricBuses();

	return 0;
}


