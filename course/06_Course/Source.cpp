#include <iostream>
#include<string.h>
#include<string>

using namespace std;

//encapsulation
//class public interface
//shallow-copy vs deep-copy
//data type & pointers
//pointer vs referece
//constructors
//prirvate vs public

//enums
//constant attributes
//static attributes
//destructor
//copy constructor
//static methods

// outside the class
enum LaptopType { GAMING, OFFICE = 15, DEV };



class Laptop {
	char* name = nullptr;
	float* pricesPerComponent = nullptr;
	int noOfComponents = 0;
	std::string brand;
	int ramSize = 0;
	LaptopType type = LaptopType::OFFICE;

	static int NO_GAMING_LAPTOPS;

public:
	static const int MIN_BRAND_SIZE = 3;
	static const int MIN_RAM_SIZE = 8;


public:
	string getBrand() {
		return this->brand;
	}

	void setBrand(string newValue) {
		//validate
		//if(strlen(newValue.c_str()))

		//int minSize = 3;
		if (newValue.length() < Laptop::MIN_BRAND_SIZE) {
			throw "Brand name too short";
		}

		this->brand = newValue;

	}

	//does NOT receive this
	static int getNoOfGamingLaptops() {
		return Laptop::NO_GAMING_LAPTOPS;
	}

	void setPrices(float* prices, int noOfPrices) {

		//avoid the memory leak
		if (this->pricesPerComponent != nullptr) {
			delete[] this->pricesPerComponent;
		}
		this->pricesPerComponent = new float[noOfPrices];
		for (int i = 0; i < noOfPrices; i++) {
			this->pricesPerComponent[i] = prices[i];
		}
		this->noOfComponents = noOfPrices;
	}

	//ctor with all params
	//const important for char*
	Laptop(const char* name,
		string brand,
		float* prices,
		int noOfPrices,
		int ramSize,
		LaptopType type) {
		//ignore the char*
		this->setBrand(brand);
		this->setPrices(prices, noOfPrices);
		this->type = type;
		this->ramSize = ramSize;

		if (type == LaptopType::GAMING)
			Laptop::NO_GAMING_LAPTOPS += 1;
	}

	Laptop() {

	}

	//class destructor
	~Laptop() {
		//clean HEAP space you allocated for the object
		delete[] name;
		delete[] pricesPerComponent;

		name = nullptr;
		pricesPerComponent = nullptr;
	}

	float getAveragePrice() {

	}
};

int Laptop::NO_GAMING_LAPTOPS = 0;


int main() {

	LaptopType type;
	//Laptop myLaptop(); // THIS IS NOT THE DEFAULT CTOR
	Laptop myLaptop;

	string newBrand = "X";
	if (newBrand.length() >= Laptop::MIN_BRAND_SIZE) {
		myLaptop.setBrand(newBrand);
	}

	//Laptop::NO_GAMING_LAPTOPS = -1;

	//myLaptop.setBrand("X");
	myLaptop.setBrand("Lenovo");

	float prices[] = { 100,234.7, 4000 };

	//Laptop none;
	Laptop superLaptop("X34", "Lenovo", 
		prices, 3, 16, LaptopType::GAMING);

	cout << endl << Laptop::getNoOfGamingLaptops();

	//for (;;) {
	//	myLaptop.setPrices(prices, 3);
	//}

	//for (;;) {
	//	Laptop* newLaptop = new Laptop("X34", "Lenovo",
	//		prices, 3, 16, LaptopType::GAMING);

	//	delete newLaptop;
 //	}

	cout << endl << "The end";
}