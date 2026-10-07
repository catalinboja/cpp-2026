#include <iostream>

int main() {

	char aSmallNumber = 10; // 1 byte
	int aNumber = 431; //4 bytes
	float aFloatValue = 3.4; //4 bytes
	double aDoubleValue = 5.66666666; //8 bytes
	bool isValid = true; // 1 byte
	bool hasSettings = false; // 1 byte
	
	//pointers
	//generic pointer
	void* pointerToAnything;
	int* pointerToAnIntValue;
	char* pointerToAChar;

	pointerToAnything = (void*)100;
	//NO - you cast the value into an address
	//pointerToAnIntValue = (int*)aNumber;
	pointerToAnIntValue = &aNumber;

	std::cout << "Value of pointer is " 
		<< pointerToAnything;
	std::cout << "Address of the int variable is "
		<< pointerToAnIntValue;

	//std::cout << std::endl
	//	<< "The value in RAM at the pointer address is"
	//	<< *((int*)pointerToAnything);

	std::cout << std::endl
		<< "The value in RAM at the pointer address is"
		<< *pointerToAnIntValue;

	std::cout << std::endl 
		<< "The value is " << aNumber;

	std::cout << std::endl << "Hello ";

	int values[100]; //please in HEAP

	int numberOfElements = 0;
	std::cout << std::endl << "How many elements: ";
	std::cin >> numberOfElements;

	int* pointerToAHugeArray;
	pointerToAHugeArray = new int[numberOfElements];
	std::cout << std::endl << "Array address in HEAP:"
		<< *pointerToAHugeArray;


	return 0;
}