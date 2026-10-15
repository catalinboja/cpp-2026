#include <iostream>
#include <string>

using namespace std;

int main() {

	//storing student grades
	// option A - static array
	int grades[100];
	// option B - dynamic array
	int* courseGrades;

	//no of elements
	int noOfStudents = 10;

	//create the array
	//grades = new int[50]; never works for static arrays
	courseGrades = new int[noOfStudents];

	//print the grades
	cout << endl << "Student grades:";
	for (int i = 0; i < noOfStudents; i++) {
		cout << " " << courseGrades[i];
	}


}