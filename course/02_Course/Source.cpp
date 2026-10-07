

// project lifecycle
// memory management
// variables, data types, pointers

// 1. read specs
// 2. define solution: input, output, algorithms
// 3. write code
// 4. compile - minimum
// 5. test - run the program and check results


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

int main() {

	std::string nume;

	//naming variables

	//snake
	char a_char_variable;
	//kebab
	//char a-char-variable;

	//Camel Case
	//lower CamelCase - for variables and functions
	char aCharVariableToPlayWith;
	//upper CameCase - for class names
	//char ACharVariableToPLayWith;

	aCharVariableToPlayWith = 'a';
	aCharVariableToPlayWith = 98;

	std::cout << "The char value is " << aCharVariableToPlayWith;

	//vb100 = 45;


	//primitive data types
	int vb2 = 1;
	int result = 34 / vb2;
	short int aShortInt;
	long int aLongInt;
	long long aVeryLongInt;
	float aRealValue;
	double aDoubleValue;
	bool aFlag = true; //false
	unsigned int onlyPositiveValues;

	int noOfStudents = 100;

	//pointers
	//is a variable
	//they store numbers
	// the value is ALWAYS an address

	void* aPointer;
	aPointer = (void*)100;
	aPointer = & aShortInt;


	std::cout << std::endl << "Result is " << result;

	return 0;
}