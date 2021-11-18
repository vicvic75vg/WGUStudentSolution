#pragma once
#include <iostream>
#include <array>
#include "degree.h"
#include <string>
using namespace std;
//string is part of the std namespace, degree is the namespace of the DegreeProgram enum
class Student {
	//Private values

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysLeftInCourse1;
	int daysLeftInCourse2;
	int daysLeftInCourse3;
	Degree studentProgram;


public:
	//Constructor function & class methods
	Student(string[],int[], Degree);
	
	//Accessor functions SHOULD be defined as const to raise error if a mutation is attempted.

	//Define print function overloads for all types
	void print() const;
	//TODO: create print() to print all student data

	//Define getters

	
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int * getDaysLeft() const;
	Degree getStudentProgram() const;




	//Define setters
	void setStudentID(string s);
	void setFirstName(string f);
	void setLastName(string l);
	void setEmailAddress(string e);
	void setAge(int a);
	void setDaysLeft(int a,int b,int c);
	void setStudentProgram(Degree d);
	


	







};

