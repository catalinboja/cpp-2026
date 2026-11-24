#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Courier {
	string name = "";
	int internalId = 0;
	int noPackagesToDeliver = 0;
public:

	//overload cast to int
	explicit operator int() {
		return this->internalId;
	}

	explicit operator string() {
		return this->name;
	}

	Courier operator+(string addedString) {
		//this->name += addedString;
		//return *this;
		Courier copy = *this;
		copy.name += addedString;
		return copy;
	}

	//pre increment
	Courier operator++() {
		this->noPackagesToDeliver += 1;
		return *this;
	}

	Courier operator++(int) {
		Courier copy = *this;
		this->noPackagesToDeliver += 1;
		return copy;
	}

	int operator()(int a, int b, int c) {
		return this->noPackagesToDeliver + a + b + c;
	}

	friend void operator<<(ostream& console, const Courier& c);
	friend void operator>>(istream& console, Courier& c);
	friend int operator+(int a, Courier c);
};

void operator<<(ostream& console, const Courier& c) {
	console << endl << "Name: " << c.name;
	console << endl << "ID: " << c.internalId;
	console << endl << "No packages: " << c.noPackagesToDeliver;
}

void operator>>(istream& console, Courier& c) {
	cout << endl << "Name is: ";
	console >> c.name;
	cout << endl << "Id is: ";
	console >> c.internalId;
	cout << endl << "Numbwer of packages: ";
	console >> c.noPackagesToDeliver;
}

//similar to  * / -
//NEVER change your object
int operator+(int a, Courier c) {
	//c.noPackagesToDeliver += a;
	return c.noPackagesToDeliver + a;
}

int main() {
	Courier c;

	cout << c;
	cin >> c;
	cout << c;


	//cast operator
	int noPackages = (int)c;
	string name = (string)c;

	int value = 5 + c;
	//value = c + 5;
	Courier d = c + " Test";
	cout << d;
	cout << c;

	//++ --
	int vb1 = 10;
	int vb2 = vb1++;
	int vb3 = ++vb1;

	d = ++c;
	d = c++;

	int someValue = c(2, 4, 6);

}