#include <iostream>
#include <string>
#include <string.h>
using namespace std;

//set defaults for attributes
//encapsulation - keep attributes private
//class public interface - start with getters and setters
//remember this - a pointer to the object taht calls the method


class Student {
private:
	int age = 0; // minimum 7
	string name = ""; //at least 2 chars / at least 2 words separated by space
	string* courses = nullptr;
	int noCourses = 0; //bigger than 0
	bool hasScholarship = false;
	bool isErasmusStudent = false;

public:
	//read access
	//receives by dfault this
	int getAge() {
		return age;
	}

	void setAge(int age) {
		//shadowing
		//age = age;

		//ALWAYS VALIDATE THE INPUT
		//this->age = age;

		if (age < 7)
		{
			// message at the console
			// NO
			//cout << endl << "Wrong value for age";
			
			// set a default
			//NO
			//this->age = 0;
			// do nothing - NO NO
			//
			// crash the program - throw an exception
			throw "Wrong value for age";
		}

		this->age = age;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		if (name.size() < 2) {
			throw "Name too short";
		}
		this->name = name;
	}

	void setIsErasmusStudent() {
		this->isErasmusStudent = true;
	}

	void unsetIsErasmusStudent() {
		this->isErasmusStudent = false;
	}

	string* getCourses() {
		//shalow copy
		//return this->courses;

		//deep copy
		//make a COPY
		string* copy = new string[this->noCourses];
		for (int i = 0; i < this->noCourses; i++) {
			copy[i] = this->courses[i];
		}
		return copy;
	}

	int getNoOfCourse() {
		return this->noCourses;
	}

	void setCourses(string* courses, int noCourses) {
		//shallow copy = DON'T
		//this->courses = courses;

		if (noCourses <= 0) {
			throw "Wrong data";
		}

		this->courses = new string[noCourses];
		this->noCourses = noCourses;

		for (int i = 0; i < noCourses; i++) {
			this->courses[i] = courses[i];
		}
	}

	void printInfo() {
		cout << endl << "My courses:";
		for (int i = 0; i < this->noCourses; i++) {
			cout << endl << this->courses[i];
		}
	}

	//special methods
	//constructors
	//copy constructor
	//destructor


	//define the default constructor
	Student() {
		cout << endl << "Default ctor";
	}

	Student(string name) {
		this->setName(name);
	}
	Student(string name, int age, string* courses, int no) {
		this->setName(name);
		this->setAge(age);
		this->setCourses(courses, no);
	}

};

int main() {

	//create an object
	Student student;
	cout << endl << "Name: " << student.getName();
	cout << endl << "Age: " << student.getAge();

	//student.setAge(-22);
	student.setAge(22);
	cout << endl << "Age: " << student.getAge();

	//student.setIsErasmusStudent(true);
	//student.setIsErasmusStudent(false);

	string demoCourses[] = {"OOP", "JAVA", "Multimedia"};
	int numbers[] = { 10,20,30 };

	student.setCourses(demoCourses, 3);

	string* yourCourses = student.getCourses();
	int no = student.getNoOfCourse();
	cout << endl << "Your courses:";
	for (int i = 0; i < no; i++) {
		cout << endl << yourCourses[i];
	}

	yourCourses[0] = "Paint";
	delete[] yourCourses;

	cout << endl << "-----------------";


	demoCourses[0] = "Math";

	student.printInfo();

	Student student2;

	Student john("John");
	Student alice("Alice", 22, demoCourses, 3);

	alice.printInfo();

	return 0;
}