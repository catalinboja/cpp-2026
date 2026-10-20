#include <string>
#include <iostream>

using namespace std;

class UniversityLaboratory {
private:
	int roomNumber = 0;
	int* studentsNumberPerDay = nullptr;
	int noOfDays = 0;
	string building = "";
public:
	int getRoomNumber() {
		return roomNumber;
	}

	void setRoomNumber(int roomNumber) {
		//shadowing
		//roomNumber = roomNumber;

		//VALIDATE THE INPUT
		if (roomNumber <= 0) {
			//return 0;
			//cout << endl << "Wrong value";
			throw "Wrong value";
		}
		this->roomNumber = roomNumber;
	}


};

int main() {
	UniversityLaboratory S2001A;
	std::cout << endl << "Room number: " 
		<< S2001A.getRoomNumber();

	//S2001A.roomNumber = 2001;

	//S2001A.setRoomNumber(-2001);
	S2001A.setRoomNumber(2001);

	std::cout << endl << "Room number: "
		<< S2001A.getRoomNumber();

	//S2001A.building = "Madgearu";
}