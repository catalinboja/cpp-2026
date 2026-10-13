#include <string>
#include <string.h>
#include <iostream>


int main() {

	//all thr variables defined in a function exist on the function stack


	//init your variables
	int noOfStudents;
	double averageGrade = 0;
	const int maxPoints = 100;
	//maxPoints = 200;

	//std::cout << "No of students: " << noOfStudents;

	//manage strings
	const char* facultyName = "CSIE"; //all strings terminate with \0
	
	std::string courseName = "OOP";
	//change values in strings
	courseName = courseName + " at CSIE";
	courseName = "Object Oriented Programming";

	//change the value C style
	facultyName = "Cybernetics";

	//strcpy(facultyName, "CSIE");

	char* otherFacultyName;
	otherFacultyName = new char[100];
	strcpy_s(otherFacultyName, 99, "CSIE"); //because I reserve 1 byte for /0

	//facultyName = new char[100];

	//static array of numbers
	int grades[1000]; //grades is a const pointer to the first int
	//dynamic array of numbers
	float* finalGrades;
	// before using dynamic arrays you need to ALLOCATE
	finalGrades = new float[10000];

	double* pointerToAverageGrade;
	pointerToAverageGrade = &averageGrade;

	//NEVER delete memory on STACK
	//delete pointerToAverageGrade;

	delete[] finalGrades;
	finalGrades = nullptr; //to avoid creatiung a dangling pointer

	//now the finalGrades is a dangling pointer without finalGrades = nullptr;
	if (finalGrades != nullptr) {
		finalGrades[0] = 10;
	}
	delete[] finalGrades;

	return 0;

}