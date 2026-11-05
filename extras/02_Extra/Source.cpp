#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception
{

};

enum StudentType { ERASMUS };

class StringUtils {
    static bool containsBucharest(string value) {
        int index = value.find("Bucharest");
        if (index >= 0)
            return true;
        else
            return false;
    }

};

class Student {
private:
    int age = 0;
    string name = "";
    char* faculty; //strcmp strlen strcpy strcpy_s strcat
    int* grades = nullptr;
    int noGrades = 0;
    string* courses = nullptr;
    int noCourses = 0;

    int nHeight = 0;
    char* Program = nullptr;

    //static int NO_OF_STUDENTS;
    //static int NO_OF_STUDENTS;
    //static int NO_OF_STUDENTS;



    int internalId = 0; //used to map some entities in the DB
public:
    void save2Db() {
        //use the internalId
    }

    float getGradesAverage() { return 0; }
    int getNoGradesBelow5() { return 0; }
    int getNoOfPassedExams() { return 0; }
    int getMaximumGrade() { return 0; }
    int getMinimumGrade() { return 0; }
    int getNoOfGtadesEqualWith(int value) { return 0; }

    static int getNoOfProffessorsInUniversity() {

    }

    bool isEnrolledAt(string courseName) { return false; }


    void setAge(int newValue) {
        if (newValue < 3) {
            throw "Wrong age"; //for now this is ok
            // throw exception("Wrong age");
            // throw new exception("Wrong age");
        }
    }

public:
    int getAge() {
        return this->age;
    }

     Student(){

     }

    Student(string name) {

    }
};

int main() {

    Student student;

    cout << "Hello World!" << student.getAge() << endl;
    // TODO: implement solution

    Student alice("Alice");
    return 0;
}
