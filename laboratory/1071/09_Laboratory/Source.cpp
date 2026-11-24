#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Arrays {
public:
	static float* copyArray(float* values, int n) {
		float* copy = new float[n];
		for (int i = 0; i < n; i++) {
			copy[i] = values[i];
		}
		return copy;
	}
};

class DeliveryRoute {
	const string destination;
	int noSegments = 0;
	float* segmentDistances = nullptr;
	float fuelConsumption = 0;
public:
	//rule of 5
	//constructor that allocates the space
	//copy constructor
	//destructor
	//operator =
	//move constructor
	//operator move =

	void setSegments(float* segments, int n) {
		if (segments == nullptr || n < 1) {
			throw "Segments error";
		}
		delete[] this->segmentDistances;
		this->segmentDistances = 
			Arrays::copyArray(segments, n);
		this->noSegments = n;
	}

	DeliveryRoute(string destination,
		float* segments, int n, float fuelRate) 
		:destination(destination), fuelConsumption(fuelRate)
	{
		this->setSegments(segments, n);
	}

	~DeliveryRoute() {
		delete[] this->segmentDistances;
		this->segmentDistances = nullptr;
	}

	DeliveryRoute(const DeliveryRoute& d)
		:destination(d.destination),
		fuelConsumption(d.fuelConsumption)
	{
		this->setSegments(d.segmentDistances, d.noSegments);
	}

	DeliveryRoute operator=(const DeliveryRoute& d) {
		if (this == &d) {
			return d;
			//return *this;
		}
		this->fuelConsumption = d.fuelConsumption;
		this->setSegments(d.segmentDistances, d.noSegments);
		return d;
	}

	DeliveryRoute(DeliveryRoute&& d): 
		destination(d.destination),
		fuelConsumption(d.fuelConsumption)
	{
		this->segmentDistances = d.segmentDistances;
		d.segmentDistances = nullptr;
		this->noSegments = d.noSegments;
		d.noSegments = 0;
	}

	void operator=(DeliveryRoute&& d) {
		if (this == &d) {
			return;
		}
		this->fuelConsumption = d.fuelConsumption;
		this->segmentDistances = d.segmentDistances;
		this->noSegments = d.noSegments;
		d.noSegments = 0;
		d.segmentDistances = nullptr;
	}
};

class Item {
	int id;
public:
	Item() : id(0) { cout << "Default\n"; }
	Item(int x) : id(x) { cout << "Params\n"; }
	Item(const Item& x) : id(x.id) { cout << "Copy\n"; }
	Item(Item&& x) : id(x.id) {
		x.id = 0; cout << "Move\n";
	}
	Item& operator=(const Item& x) {
		id = x.id; cout << "Copy assign\n"; return *this;
	}
	Item& operator=(Item&& x) {
		id = x.id; x.id = 0;
		cout << "Move assign\n"; return *this;
	}
	~Item() { cout << "Destructor\n"; }

	void test(Item x) { Item y(move(x)); }
};

int main() {

	float segments[] = { 10.5, 23.8, 20, 14.7 };
	DeliveryRoute dr("Bucharest", segments, 4, 10);
	DeliveryRoute drCopy = dr;
	DeliveryRoute drOherCopy(dr);
	drOherCopy = drCopy = dr;

	DeliveryRoute theRoute = std::move(dr);
	DeliveryRoute theRoute2(std::move(dr));

	theRoute = move(drCopy);

	Item a, b(5), c(b);
	Item d(move(b));
	a = c;
	c = move(d);
	a.test(c);
	a.test(move(c));
}