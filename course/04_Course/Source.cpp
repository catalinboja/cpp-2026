#include <string>
#include <string.h>
#include <iostream>

using namespace std;

struct Student {
	std::string name = "";
	int age;
	int grade = 0;
	float average = 0;
	char* program = nullptr;
};




void printStudent(Student student) {
	cout << endl << "Student name: "
		<< student.name;
	cout << endl << "Student grade: "
		<< student.grade;
	cout << endl << "Student average: "
		<< student.average;
	if (student.program != nullptr) {
		cout << endl << "Student program: "
			<< student.program;
	}
}

void readStudentData(Student *student) {
	(*student).name = "John";
	student->grade = 10;
	student->average = 9.5;
	//student.program = "Info";
	//you need + 1 for \0
	student->program = new char[strlen("Info") + 1];
	strcpy_s(student->program, strlen("Info") + 1, "Info");
}

void readStudentData2(Student& student) {
	student.name = "Alice";
	student.grade = 10;
	student.average = 9.5;
	//student.program = "Info";
	//you need + 1 for \0
	student.program = new char[strlen("Cybernetics") + 1];
	strcpy_s(student.program, strlen("Cybernetics") + 1, "Cybernetics");
}


class SuperStudent {
private:
	std::string name = "";
	int age = 0;
	int grade = 0;
	float average = 0;
	char* program = nullptr;
public:
	//the class public interface - all public functions
	void printStudent() {
		cout << endl << "Student name: "
			<< this->name;
		cout << endl << "Student grade: "
			<< this->grade;
		cout << endl << "Student average: "
			<< this->average;
		if (this->program != nullptr) {
			cout << endl << "Student program: "
				<< this->program;
		}
	}

	//read access
	//you get for free SuperStudent* this
	string getName() {
		return this->name;
	}

	//write access
	void setName(string newName) {
		//it's bad
		this->name = newName;
	}
};

int main() {

	char* facultyName;
	char universityName[100];

	int noOfStudents = 100;

	//students names
	std::string* names;
	char** namesAsInC;

	names = new std::string[noOfStudents];

	int* grades;
	int gradesAsStaticArray[1000];

	grades = new int[noOfStudents];

	float* yearAverage;
	yearAverage = new float[noOfStudents];

	//more efficient using structs
	Student* studentsList;
	studentsList = new Student[noOfStudents];

	Student stud;
	cout << endl << "Name: " << stud.name;
	printStudent(stud);
	readStudentData(&stud);
	printStudent(stud);
	readStudentData2(stud);
	printStudent(stud);

	SuperStudent superStud;
	SuperStudent alice;
	SuperStudent john;
	cout << endl << "Super name" << alice.getName();
	alice.printStudent();
	john.printStudent();


}