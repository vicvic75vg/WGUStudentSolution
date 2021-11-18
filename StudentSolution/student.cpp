#include "student.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//Implementation of constructor with 7 parameters
Student::Student(string stringArr[],int intArr[], Degree p) {
	studentID = stringArr[0];
	firstName = stringArr[1];
	lastName = stringArr[2];
	emailAddress = stringArr[3];
	age = intArr[0];
	daysLeftInCourse1 = intArr[1];
	daysLeftInCourse2 = intArr[2];
	daysLeftInCourse3 = intArr[3];
	studentProgram = p;
}

//Implementation of print function overloads
void Student::print() const {
	//Prints all strings using printf, casts enum studentProgram to int and
	//retrieves string from array degreeProgramString
	printf("First Name: %s ", firstName.c_str());
	printf("\tLast Name: %s ", lastName.c_str());
	printf("\tAge: %d ", age);
	printf("\tDays in course: {%d,%d,%d}", daysLeftInCourse1, daysLeftInCourse2, daysLeftInCourse3);
	printf("\tDegree program: %s ",degreeProgramString[int(studentProgram)].c_str());
	
}
	

//Implementations of getters
string Student::getStudentID() const {
	return studentID;
};

string Student::getFirstName() const { 
	return firstName;
};

string Student::getLastName() const {
	return lastName;
};
string Student::getEmailAddress() const {
	return emailAddress;
};
int Student::getAge() const {
	return age;

};

int * Student::getDaysLeft() const {
	int result[3] = {daysLeftInCourse1,daysLeftInCourse2,daysLeftInCourse3};
	return result;
} ;
Degree Student::getStudentProgram() const {
	return studentProgram;
};

//Implementation of setters
void Student::setStudentID(string s) {
	studentID = s;
};
void Student::setFirstName(string f) {
	firstName = f;
};
void Student::setLastName(string l) {
	lastName = l;
};
void Student::setEmailAddress(string e) {
	emailAddress = e;
};
void Student::setAge(int a) {
	age = a;
};
void Student::setDaysLeft(int a,int b,int c) {

	daysLeftInCourse1 = a;
	daysLeftInCourse2 = b;
	daysLeftInCourse3 = c;
};
void Student::setStudentProgram(Degree d) {
	studentProgram = d;
}

