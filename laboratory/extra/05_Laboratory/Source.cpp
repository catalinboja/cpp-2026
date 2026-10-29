#include <iostream>
#include <string>
#include <string.h>

using namespace std;

enum SourceType { ONLINE, LOCAL = 10, FUTURE = 20 };

class Weather {
	char* location = nullptr;
	string* conditions = nullptr;
	int noOfConditions = 0;
	float currentTemp = 0.0;

	//option 1 - DON'T
	//enum SourceType {ONLINE, LOCAL = 10, FUTURE = 20 };

	SourceType type = SourceType::LOCAL;

	//sourceType //online service, local sensor, future estimation
	//	int type; //0 - online, 1 local 2 future
	//string type; //online/Online/ONLINE/ONINE, sensor, future

public:
	void setLocation(const char* newLocation) {
		//DON"T shallow copy
		//this->location = newLocation;

		if (newLocation == nullptr || strlen(newLocation) < 3) {
			throw "Location name is too short";
		}

		//deep copy
		this->location = new char[strlen(newLocation) + 1];
		strcpy_s(this->location, strlen(newLocation) + 1, newLocation);
	}

	void setConditions(string* newConditions, int noValues) {
		
		if (newConditions == nullptr) {
			throw "null ptr as input";
		}
		
		this->conditions = new string[noValues];
		this->noOfConditions = noValues;
		for (int i = 0; i < noValues; i++) {
			this->conditions[i] = newConditions[i];
		}
	}

	Weather() {

	}

	Weather(const char* location,
		float temperature,
		string* conditions,
		int noOfConditions,
		SourceType type) {

		this->setConditions(conditions, noOfConditions);
		this->setLocation(location);
		this->currentTemp = temperature;
		this->type = type;
	}
};

int main() {

	SourceType newType;
	Weather w; //default ctor
	Weather* pWeather = new Weather(); //default ctor

	w.setLocation("Bucharest");

	string conditions[] = { "sunny", "cloudy" };
	int values[] = { 10,2,56,78,8 };

	w.setConditions(conditions, 2);

	Weather bucharestWeather(
		"Bucharest", 15, conditions, 2, SourceType::LOCAL);




	return  0;
}