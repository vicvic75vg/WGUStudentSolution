
#pragma once
#include <string>
#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;
class Roster {
	//Must use the add() method to create new student objects in the Roster.
	//The Student objects will be stored as pointers in classRosterArray
private:
	//This array of pointers will contain pointers to all student objects in studentDataTable

	int maxSize = 20;
	int currentRosterSize = 0;

	Student *classRosterArray[20];

public:
	//Constructor	

	Roster(const string someData[], int studentDataSize, const int maxSize);
	~Roster();

	void printAll();
	void add(string studentID, string first_name, string last_name, string email_address, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree studentProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(Degree degree);
	void remove(string studentID);
	int getCurrentRosterSize();

	Student **getClassRosterArray();
};
