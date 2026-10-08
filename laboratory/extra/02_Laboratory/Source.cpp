//memory management 
//pointers

#include <iostream>
using namespace std;

int main() {

	bool isValid = true;
	//an int variable to store number of students
	int noOfStudents = 32;
	float minimumPoints = 5.0;

	//pointer
	//is a variable
	//the purpose is to store an address of something
	int *pointerToNoOfStudents;
	char* pointerToSomething;

	//init
	noOfStudents = 53;
	//get the address of a known variable
	pointerToNoOfStudents = &noOfStudents;

	///use variables
	//print them
	cout << endl << "No of students is " << noOfStudents;
	cout << endl << "Same value using the pointer " <<
		*pointerToNoOfStudents;
	cout << endl << "The address stored by the pointer is " <<
		pointerToNoOfStudents;

	*pointerToNoOfStudents = 64;
	cout << endl << "No of students is " << noOfStudents;

	//get the address of something you create in HEAP
	pointerToNoOfStudents = new int[1000];

	//release space - ONLY for pointers
	//what is created with [] is deleted with []
	//works ONLY for addresses in HEAP

	delete[] pointerToNoOfStudents;
	pointerToNoOfStudents = nullptr;

	if (pointerToNoOfStudents != nullptr) {
		//copy
	}


	return 0;
}