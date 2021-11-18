
#include <string>
#include "ROSTER.H"
#include "degree.h"
#include <sstream>
#include <regex>

using namespace std;
Roster::Roster(const string data[5], int studentDataSize, int maxSize) {
	//Iterates over strings of studentData and converts strings to Student objects
	
	for (int i = 0; i < studentDataSize; i++) {
		string stringArray[4];
		int intArray[4];
		Degree degree = Degree::ERROR; //Default
		stringstream ss(data[i]);


		for (int i = 0; ss.good(); i++) {
			string substr;
			if (i <= 3) {
				getline(ss, substr, ',');
				stringArray[i] = substr;
			}
			else if (i > 3 && i <= 7) {
				getline(ss, substr, ',');
				intArray[i - 4] = stoi(substr);

			}
			else if(i > 7){
				getline(ss, substr, ',');
				if (substr == "SECURITY") {
					degree = Degree::SECURITY;
				}
				else if (substr == "NETWORK") {
					degree = Degree::NETWORK;
				}
				else if (substr == "SOFTWARE") {
					degree = Degree::SOFTWARE;
				}
			}
		}
		classRosterArray[i] = new Student(stringArray, intArray, degree);
		currentRosterSize++;

	}
	
}
Roster::~Roster() {
	for (int i = 0; i < currentRosterSize; i++) {
		delete classRosterArray[i];
	}
}
void Roster::printAll() {
	for (int i = 0; i < currentRosterSize; i++) {
		classRosterArray[i]->print();
	}

}
void Roster::add(string studentID,string first_name,string last_name, string email_address, int age,int daysInCourse1,int daysInCourse2,int daysInCourse3, Degree studentProgram) {


	try {
		string stringInputArr[4] = { studentID,first_name,last_name,email_address };
		int intInputArr[4] = { age,daysInCourse1,daysInCourse2,daysInCourse3 };


		classRosterArray[currentRosterSize] = new Student(stringInputArr,intInputArr,studentProgram);
		currentRosterSize++;

	}
	catch(int e) {

		cout << "An exception occured while adding to current roster:" << e << endl;
	}


	//This method takes all studetn parameters and creates a student objects,
	//that then adds the object to the classRosterArray

}
void Roster::printInvalidEmails() {
	for (int i = 0; i < currentRosterSize; i++) {
		string email = classRosterArray[i]->getEmailAddress();
		regex e("^[^@]+@[^@]+\\.[^@]+$");

		if (!(regex_match(email, e))) {
			cout << "Invalid email: " << email << "\t" << endl;
		}
		else {
			continue;
		}
	}
}
Student **Roster::getClassRosterArray() {
	return this->classRosterArray;
}

void Roster::printAverageDaysInCourse(string studentID) {
	Student **roster = this->classRosterArray;
	for (int i = 0; i < currentRosterSize; i++) {
		if (roster[i]->getStudentID() == studentID) {
			int *result = roster[i]->getDaysLeft();
			int avg = (result[0] + result[1] + result[2]) / 3;
			cout << "Average days in course for " << roster[i]->getFirstName() << " " << roster[i]->getLastName() << ": " << avg << endl;
		}
	}

}
void Roster::printByDegreeProgram(Degree degree) {
	Student** roster = this->classRosterArray;
	for (int i = 0; i < currentRosterSize; i++) {
		if (roster[i]->getStudentProgram() == degree) {
			roster[i]->print();
		}
	}
}
int Roster::getCurrentRosterSize() {
	return currentRosterSize;
};
void Roster::remove(string studentID) {
	Student** roster = this->classRosterArray;

	for (int i = 0; i <= currentRosterSize; i++) {
		if (i == currentRosterSize) {
			cout << "Student ID of: " << studentID << " could not be found." << endl;
			return;
		}else if(roster[i]->getStudentID() == studentID) {
			for (int j = i; j < currentRosterSize - 1; j++) {
				roster[j] = roster[j + 1];
			}
			currentRosterSize--;
			return;
		}
	}
}

