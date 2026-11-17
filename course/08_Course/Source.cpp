#include <iostream>
#include <string>

using namespace std;

//the rule of 3 - destructor, copy ctor and operator =
//the rule of 5 - destructor, copy ctor, move ctro, operator =, move operator =

class Utility {
public:
	static float* clone(float* values, int n) {
		if (values == nullptr || n <= 0) {
			throw "Wrong input";
		}
		float* copy = new float[n];
		for (int i = 0; i < n; i++) {
			copy[i] = values[i];
		}
		return copy;
	}
};

class Company {
	const string name;
	float* montlhyIncome = nullptr;
	int noOfMonths = 0;
	int noOfEmployees = 0;
public:
	void setIncome(float* values, int noMonths) {
		if (values == nullptr || noMonths <= 0)
			throw "Wrong input";

		delete[] this->montlhyIncome;
		this->montlhyIncome = 
			Utility::clone(values, noMonths);
		this->noOfMonths = noMonths;
	}

	Company():name("ACME Inc"), noOfEmployees(0) {

	}

	Company(string companyName,
		float* incomes, int noMonths, int noEmp)
		:name(companyName), noOfEmployees(noEmp)
	{
		this->setIncome(incomes, noMonths);
	}

	//copy ctor
	Company(const Company& c): name(c.name) {
		this->noOfEmployees = c.noOfEmployees;
		//this->name = c.name;
		this->setIncome(c.montlhyIncome, c.noOfMonths);
	}


	//move constructor
	Company(Company&& c)
		: name(c.name), noOfEmployees(c.noOfEmployees) {
		//option 1
		this->montlhyIncome = c.montlhyIncome;
		c.montlhyIncome = nullptr;
		this->noOfMonths = c.noOfMonths;
		c.noOfMonths = 0;

		//option 2 - NOT efficient. DON'T
		//this->setIncome(c.montlhyIncome, c.noOfMonths);
		//delete[] c.montlhyIncome;
		//c.montlhyIncome = nullptr;
		//c.noOfMonths = 0;

	}

	~Company() {
		delete[] this->montlhyIncome;
		this->montlhyIncome = nullptr;
	}

	//overload operator =
	void operator=(const Company& c) {
		this->noOfEmployees = c.noOfEmployees;
		this->setIncome(c.montlhyIncome, c.noOfEmployees);
		//this->name = c.name;
	}

	//the move operator =
	void operator=(Company&& c) {
		this->noOfEmployees = c.noOfEmployees;
		this->montlhyIncome = c.montlhyIncome;
		c.montlhyIncome = nullptr;
		this->noOfMonths = c.noOfMonths;
		c.noOfMonths = 0;
	}

	//option 2
	void operator+=(int value) {
		this->noOfEmployees += value;
	}

	//overload operator <
	bool operator<(Company& c) {
		if (this->noOfEmployees < c.noOfEmployees)
			return true;
		else return false;
	}

	bool operator == (Company c) {
		if (this->noOfEmployees == c.noOfEmployees)
			return true;
		else return false;
	}


	friend void operator<<(ostream& console, Company& c);


};
//option 1 - global method
//increase the number of employees
//void operator+=(Company& c, int value) {
//	c.noOfEmployees += value;
//}

//for all operator with a 1st param different than your class
// only by global method

void operator<<(ostream& console, Company& c) {
	console << endl << c.noOfEmployees;
}

int main() {
	Company c;
	float values[] = { 1000, 567.0, 899.33 };
	Company microsoft("Microsoft", values, 3, 160000);

	//test copy ctor
	Company another = microsoft;
	Company acme(microsoft);

	//test move costructor
	Company anotherWithData = std::move(microsoft);
	Company anotherOne(move(anotherWithData));


	//overloading operators

	acme = anotherOne; //acme.oprator=(anotherOne)
	acme = move(anotherOne);
	acme += 1; //operator+=(acme, 1) vs acme.operator+=(int)
	cout << acme;
	acme = acme + 5; // - * /
	acme = 5 + acme;
	acme = acme + anotherOne;
	if (acme < anotherOne) { //> >= <=
		cout << endl << "ACME has less employees";
	}
	if (acme == anotherOne) {
		cout << endl << "Have same number of eomployees";
	}

	acme++;
	++acme;
	!acme;


}