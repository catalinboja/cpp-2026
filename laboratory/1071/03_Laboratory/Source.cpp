#include <iostream>
#include <string>

using namespace std;

//a function that inits any array of integers with a given value
void initArray(int* theArray, int noElements, int value) {
	for (int i = 0; i < noElements; i++) {
		theArray[i] = value;
	}
}

// a function to init an int value from the console
int initValue(int valueToChange) {
	cout << endl << "The new value ?";
	cin >> valueToChange;
	return valueToChange;
}

void initValue2(int* pointerToVariableToChange) {
	int newValue;
	cout << endl << "The new value ?";
	cin >> newValue;
	*pointerToVariableToChange = newValue;
}

int main() {
	std::cout << std::endl << "Hello";

	// char size = 1 byte = 8 bits
	char initial = 'C'; //different than "C"
	char* studentName;
	studentName = &initial;
	studentName = new char[1000];

	//we store the grades for any number of students

	//plan to use dynamic arrays
	//1. define the pointer to the future array - set it to nullptr

	int noOfStudents = 0;
	int* studentGrades = nullptr; //NULL
	
	//2. determine how many values you need in array
	//cout << endl << "No of students: ";
	//cin >> noOfStudents;

	//noOfStudents = initValue(noOfStudents);
	initValue2(&noOfStudents);
	cout << endl << "After init: " << noOfStudents;

	//3. allocate space in HEAP
	studentGrades = new int[noOfStudents];

	//4. use it

	//for (int i = 0; i < noOfStudents; i++) {
	//	studentGrades[i] = 0;
	//}
	initArray(studentGrades, noOfStudents, 10);

	cout << endl << "Grades are: ";
	for (int i = 0; i < noOfStudents; i++) {
		cout << endl << "Grade for student " << i << " is " <<
			studentGrades[i];
	}

	cout << endl << "The end";

	delete[] studentName;
	delete[] studentGrades;
}