#include <string>
#include <string.h>

using namespace std;

class Laboratory {
private:
	char* building = nullptr;

	std::string* coursesSchedule = nullptr;
	int noCourses = 0;

	int* noOfStudentsPerDay = nullptr;
	int noOfDays = 0;

	int noOfComputers = 0;
	std::string roomName = "";

	bool isAvailable = true;
public:
	//public interface
	//give read access
	int getNoOfComputers() {
		return this->noOfComputers;
	}

	std::string getRoomName() {
		return this->roomName;
	}

	int* getNoOfStudentsPerDay() {
		//NEVER
		//return this->noOfStudentsPerDay;
		//create a copy
		if (this->noOfDays > 0) { //check the pointer for != nullptr
			int* copy = new int[this->noOfDays];
			for (int i = 0; i < this->noOfDays; i++) {
				copy[i] = this->noOfStudentsPerDay[i];
			}
			return copy;
		}

		return nullptr;
	}

	std::string* getCourseSchedule() {

		if (this->coursesSchedule == nullptr)
			return nullptr;

		string* copy = new string[this->noCourses];
		for (int i = 0; i < this->noCourses; i++) {
			copy[i] = this->coursesSchedule[i];
		}

		return copy;
	}

	char* getBuilding() {

		if (this->building == nullptr)
			return nullptr;

		char* copy = new char[strlen(this->building) + 1];
		strcpy_s(copy, strlen(this->building) + 1, this->building);
		return copy;
	}

	void setNoOfComputers(int value) {
		//ALWAYS validate
		if (value < 0) {
			throw "Wrong value";
		}
		this->noOfComputers = value;
	}


};

int main() {

	Laboratory l;
	//l.roomName = "S2320";

}