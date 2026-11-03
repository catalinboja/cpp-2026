#include <iostream>
#include <string.h>
#include <string>
using namespace std;

enum  ServiceType {MOTO, BUS, TRUCK, CAR};

class Service {
	char* name = nullptr;
	string address = "";
	int noOfVehicles = 0;
	bool isClosed = false;
	enum ServiceType type = ServiceType::CAR;

	static int NO_BUCHAREST_SERVICES;
public:

	static const int MIN_NAME_SIZE = 5;

	char* getName() {
		//return this->name;
		if (this->name != nullptr) {
			char* copy = new char[strlen(this->name) + 1];
			strcpy_s(copy, strlen(this->name) + 1, this->name);
			return copy;
		}
		else {
			return nullptr;
		}
	}

	void setName(const char* newName) {
		if (strlen(newName) < Service::MIN_NAME_SIZE) {
			throw "Invalid name";
		}

		int newNameSize = strlen(newName) + 1;
		delete[] this->name;
		this->name = new char[newNameSize];
		strcpy_s(this->name, newNameSize, newName);
	}

	static bool containsBucharest(string value) {
		int index = value.find("Bucharest");
		if (index >= 0)
			return true;
		else
			return false;
	}

	void setAddress(string newAddress) {
		if (newAddress.length() < Service::MIN_NAME_SIZE) {
			throw "Address error";
		}

		if (Service::containsBucharest(this->address))
			Service::NO_BUCHAREST_SERVICES -= 1;

		this->address = newAddress;
		if (Service::containsBucharest(newAddress))
			Service::NO_BUCHAREST_SERVICES += 1;
	}

	Service(const char* name, 
		string address, 
		int noOfVehicles,
		ServiceType type) {

		this->setAddress(address);
		this->setName(name);
		this->noOfVehicles = noOfVehicles;
		this->type = type;
	}

	~Service() {
		cout << endl << "Destructor !!!";
		delete[] this->name;
		this->name = nullptr;

		if (Service::containsBucharest(this->address))
			Service::NO_BUCHAREST_SERVICES -= 1;
	}

	static int getServicesInBucharest() {
		return Service::NO_BUCHAREST_SERVICES;
	}
};

int Service::NO_BUCHAREST_SERVICES = 0;

int main() {

	//Service service;
	Service service(
		"TheService",
		"Calea Dorobanti, Bucharest",
		2,
		ServiceType::BUS);

	service.setAddress("Ploiesti");

	char* name = service.getName();
	if(name != nullptr)
		cout << endl << "Service name: " << service.getName();

	service.setName("SuperService");
	cout << endl << "Serivice name: " << service.getName();

	//test the destructor
	Service* pService = new Service("TheService",
		"Calea Dorobanti, Bucharest",
		2,
		ServiceType::BUS);
	delete pService;
	pService = nullptr;

	{
		Service service2(
			"TheService",
			"Calea Dorobanti, Bucharest",
			2,
			ServiceType::BUS);
	}

	cout << endl << "No of Services: " << 
		Service::getServicesInBucharest();

	cout << endl << "The end";


}
