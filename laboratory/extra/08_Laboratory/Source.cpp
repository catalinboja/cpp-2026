#include <iostream>
#include <string>
#include <string.h>
 
using namespace std;

enum TableType {STANDARD, TERRACE, PRIVATE};

class RestaurantTable {
	char* tableName = nullptr;
	int capacity = 0;
	float minimumSpend = 0.0;
	bool isAvailable = false;
	TableType type = TableType::STANDARD;
	static int TOTAL_AVAILABLE_TABLES;
public:

	static const int MIN_SPEND_PRIVATE = 200;

	int getCapacity() {
		return this->capacity;
	}

	char* getName() {
		if (this->tableName == nullptr) {
			return nullptr;
		}
		char* copy = new char[strlen(this->tableName) + 1];
		strcpy_s(copy, strlen(this->tableName) + 1, this->tableName);
		return copy;
	}

	void setName(const char* name) {
		if (name == nullptr || strlen(name) < 5) {
			throw "Invalid name";
		}
		delete[] this->tableName;
		this->tableName = new char[strlen(name) + 1];
		strcpy_s(this->tableName, strlen(name) + 1, name);
	}

	RestaurantTable(const char* name, int capacity, float minim) {
		if (capacity <= 1) {
			throw "Invalid capacity";
		}
		if (minim < 0) {
			throw "Invalid minimum spend";
		}
		this->setName(name);
		this->capacity = capacity;
		this->minimumSpend = minim;
		this->type = TableType::STANDARD;
	}

	RestaurantTable(const char* name, int capacity, float minim,
		bool isAvailable, TableType type) {
		if (capacity <= 1) {
			throw "Invalid capacity";
		}
		if (minim < 0) {
			throw "Invalid minimum spend";
		}
		if (type == TableType::PRIVATE && minim < MIN_SPEND_PRIVATE) {
			throw "Invalid minim spend for private tables";
		}
		this->setName(name);
		this->capacity = capacity;
		this->minimumSpend = minim;
		this->type = TableType::STANDARD;
		this->isAvailable = isAvailable;
		this->type = type;
		if (isAvailable == true)
			RestaurantTable::TOTAL_AVAILABLE_TABLES += 1;
	}

	RestaurantTable() {

	}

	void print() {
		cout << endl << "Name: " << this->tableName;
		cout << endl << "Capacity: " << this->capacity;
		cout << endl << "Minimum spend: " << this->minimumSpend;
		cout << endl << "Is availabe: " << this->isAvailable;
		cout << endl << "Type: " << this->type;
	}

	~RestaurantTable() {
		delete[] this->tableName;
		this->tableName = nullptr;
	}

	bool checkReservation(int noPersons, float estimatedSpend, bool isVIP) {
		if (this->isAvailable == false) {
			return false;
		}
		if (noPersons <= 0 || noPersons > this->capacity) {
			return false;
		}

		if (estimatedSpend < 0) {
			return false;
		}

		if (this->type == TableType::TERRACE && noPersons < 2) {
			return false;
		}

		if (this->type == TableType::PRIVATE &&
			noPersons >= 4 &&
			estimatedSpend >= this->minimumSpend) {
			return true;
		}
		else {
			return false;
		}
		return true;
	}

	float getReservationCost(int noPersons, int noHours, bool isWeekend) {

		if (this->isAvailable == false || noPersons <= 0 || noHours <= 0) {
			return -1;
		}

		float baseCost = 0;
		if (this->type == STANDARD)
			baseCost = 10;
		if (this->type == TERRACE)
			baseCost = 15;
		if (this->type == PRIVATE)
			baseCost = 25;

		if (noHours > 3) {
			baseCost *= 1.2;
		}

		if (isWeekend == true) {
			baseCost *= 1.15;
		}

		if (baseCost < 0.3 * this->minimumSpend) {
			baseCost = 0.3 * this->minimumSpend;
		}
	}

	RestaurantTable(RestaurantTable& r) {

	}

};

int RestaurantTable::TOTAL_AVAILABLE_TABLES = 0;

int main() {

	RestaurantTable table;

	if(table.getName() != nullptr)
		cout << endl << "Table name: " << table.getName();

	//table.setName("ttt");

	table.setName("Window table");
	if (table.getName() != nullptr)
		cout << endl << "Table name: " << table.getName();

	RestaurantTable t1("Balacony table", 6, 100);
	if (t1.getName() != nullptr)
		cout << endl << "Table name: " << t1.getName();

	t1.print();

	RestaurantTable t2("Ballroom table", 20, 500, true, TableType::PRIVATE);
	t2.print();

	RestaurantTable* pt = new RestaurantTable();
	delete pt;

	{
		RestaurantTable temp;
	}

	if (t2.checkReservation(10, 1000, true)) {
		cout << endl << "You got the reservation";
	}

	float cost = t2.getReservationCost(10,10,false);
	cout << endl << "Reservation cost: " << cost;

}