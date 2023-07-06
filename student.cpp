#include <iostream>
#include <string>
#include "student.h"

using namespace std;

void Student::SetStudID(string studIden) {
	studentID = studIden;
	return;
}

void Student::SetFName(string fName) {
	firstName = fName;
	return;
}

void Student::SetLName(string lName) {
	lastName = lName;
	return;
}

void Student::SetEmailAddr(string email) {
	emailAddress = email;
	return;
}

void Student::SetAge(int ageNum) {
	age = ageNum;
	return;
}

void Student::SetDaysCompCrs(int* daysCompCrs) {   
	for (int i = 0; i < 3; i++) { 
		daysToCompleteCourse[i] = daysCompCrs[i];
	}
	return;
}

void Student::SetDaysCompCrsString(int* daysToCompleteCourse) {
	string days = "{";
	for (int i = 0; i < 3; i++) {
		days += to_string(daysToCompleteCourse[i]);
		if (i != 2) {
			days += ", ";
		}
		else {
			days += "}";
		}
	}
	return;
}

void Student::SetDegrProg(DegreeProgram degrProg) {
	degreeProgram = degrProg;
	return;
}

string Student::GetStudID() const {
	return studentID;
}

string Student::GetFName() const {
	return firstName;
}

string Student::GetLName() const {
	return lastName;
}

string Student::GetEmailAddr() const {
	return emailAddress;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysToCompCrs() {
	return daysToCompleteCourse;
}

string Student::GetDaysCompCrsString() {
	return days;
}

DegreeProgram Student::GetDegrProg() const {
	return degreeProgram;
}

string Student::GetDegrProgString() const {
	return degrProgStrings[(int)degreeProgram];
}

Student::Student(string sID, string fName, string lName, string eAddr, int a, int* da, DegreeProgram dp) {
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailAddress = eAddr;
	age = a;
	daysToCompleteCourse[0] = da[0];
	daysToCompleteCourse[1] = da[1];
	daysToCompleteCourse[2] = da[2];
	degreeProgram = dp;
}

Student::~Student() {
}

void Student::Print() {
	cout << studentID << "\t First Name:  " << firstName << "\t Last Name:  " << lastName << "\t Age:  " << age;
	cout << "\t daysInCourse:  {" << daysToCompleteCourse[0] << ", " << daysToCompleteCourse[1] << ", " << daysToCompleteCourse[2] << "} Degree Program:  " << degrProgStrings[(int)degreeProgram] << endl;
	return;
}