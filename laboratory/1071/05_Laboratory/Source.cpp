#include <iostream>
#include <string>
#include <string.h>

using namespace std;

//option 1
 enum CourseType { ONLINE, IN_PERSON, HYBRID };


class Course {

	//option 2
	//enum CourseType { ONLINE = 10, IN_PERSON = 20, HYBRID = 30 };

	char* name = nullptr;
	int credits = 0;
	int noOfStudents = 0;
	int noOfAttendances = 0;
	bool isAttendanceRequired = false;
	float averageGrade = 0.0;

	//int courseType; //0 - online, 1 - in person, 2 - hybrid
	//string courseType; //online/ONLINE, inPerson, hybrid

	CourseType type = CourseType::IN_PERSON;


public:
	char* getName() {
		//DON'T - shallow copy
		//return this->name;

		//deep copy
		//+1 because of \0
		char* copy = new char[strlen(this->name) + 1];
		int maxNameSize = 50;
		strcpy_s(copy, maxNameSize, this->name);

		return copy;
	}

	void setName(const char* name) {
		//don't
		//this->name = name;

		if (strlen(name) < 2) {
			throw "Name too short";
		}

		int maxNameSize = 50;
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, maxNameSize, name);

	}

	int getCredits() {
		return this->credits;
	}

	void setCredits(int credits) {
		//shadowing
		//credits = credits;

		if (credits <= 0) {
			throw "Wrong credits value";
		}

		this->credits = credits;
	}

	void setType(CourseType type) {
		this->type = type;
	}

	CourseType getType() {
		return this->type;
	}


	//constructor with all values
	Course(const char* name, 
		int noOfStudents, 
		int noOfAttendances, 
		bool isAttendanceRequired, 
		int credits,
		float averageGrade,
		CourseType type
		) {
		this->setName(name);
		this->setCredits(credits);
		this->setType(type);
		this->noOfStudents = noOfStudents;
		this->noOfAttendances = noOfAttendances;
		this->averageGrade = averageGrade;
		this->isAttendanceRequired = isAttendanceRequired;
	}
	
	Course() {

	}

};

// option 3
//enum CourseType { ONLINE = 10, IN_PERSON = 20, HYBRID = 30 };


int main() {
	CourseType theType;
	theType = CourseType::ONLINE;

	Course course;

	course.setName("OOP");
	cout << endl << "Course name: " << course.getName();
	course.setType(CourseType::HYBRID);
	//cout << endl << "Course type: " << course.getType();

	Course oop("OOP", 100, 5, true, 6, 
		9.5, CourseType::IN_PERSON);
}