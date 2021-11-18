// main.cpp: This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <array>
#include <string>
#include <cstdio>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;


int main()
{

	const string studentData[] =

	{ "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Victor,Garcia,vicvic75.vg@gmail.com,24,10,10,10,SOFTWARE" };

	Roster classRoster(studentData,5,20);
	
	

	cout << "\tScripting and Programming - Applications C867" << endl;
	cout << "\tProgamming Language Used: C++ " << __cplusplus << endl;
	cout << "\tStudent ID:  #001062489, Victor M Garcia" << endl;


	classRoster.printAll();
	classRoster.printInvalidEmails();



	Student **arr = classRoster.getClassRosterArray();
	//F.4 loop through classRosterArray and for each element
	for (int i = 0; i < classRoster.getCurrentRosterSize(); i++) {
		classRoster.printAverageDaysInCourse(arr[i]->getStudentID());
	};

	classRoster.printByDegreeProgram(Degree::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");



	


	

} 