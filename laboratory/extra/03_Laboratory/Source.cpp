#include <iostream>
#include <string>

using namespace std;

void initArray(int* values, int noOfElements, int newValue) {
	for (int i = 0; i < noOfElements; i++) {
		values[i] = newValue;
	}
}

void readAnIntFromConsole(int *anyVariable) {
	cout << endl << "New value is: ";
	int newValue;
	cin >> newValue;
	*anyVariable = newValue;
}

void readAnIntFromConsole2(int &anyVariable) {
	cout << endl << "New value is: ";
	int newValue;
	cin >> newValue;
	anyVariable = newValue;
}

int main() {

	//storing student grades
	// option A - static array
	int grades[100];
	// option B - dynamic array
	int* courseGrades;
	char* name = nullptr;

	//no of elements
	int noOfStudents = 10;

	readAnIntFromConsole(&noOfStudents);

	//create the array
	//grades = new int[50]; never works for static arrays
	courseGrades = new int[noOfStudents];

	//init the values
	//for (int i = 0; i < noOfStudents; i++) {
	//	courseGrades[i] = 0;
	//}
	initArray(courseGrades, noOfStudents, 5);

	//print the grades
	cout << endl << "Student grades:";
	for (int i = 0; i < noOfStudents; i++) {
		cout << " " << courseGrades[i];
	}


}