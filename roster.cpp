#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

void Roster::parse(string studentData) {

	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day3 = stoi(studentData.substr(lhs, rhs - lhs));
	
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string dp = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degree = DegreeProgram::SOFTWARE;

	if (dp == "SOFTWARE") {
		degree = DegreeProgram::SOFTWARE;
	}

	else if (dp == "NETWORK") {
		degree = DegreeProgram::NETWORK;
	}

	else if (dp == "SECURITY") {
		degree = DegreeProgram::SECURITY;
	}

	add(studentID, firstName, lastName, emailAddress, age, day1, day2, day3, degree);

	return;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int temp[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* o = new Student(studentID, firstName, lastName, emailAddress, age, temp, degreeProgram);
	classRosterArray[craIndex++] = o;

	return;
}

void Roster::remove(string studentID) {
	bool removed = false;

	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			string sidToRemove = classRosterArray[i]->GetStudID();
			if (sidToRemove == studentID) {
				classRosterArray[i] = NULL;
				removed = true;
			}
		}
	}

	if (!removed) {
		cout << "The student with that ID was not found." << endl;
	}

	return;
}

void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;

	return;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		string sid = classRosterArray[i]->GetStudID();

		if (sid == studentID) {
			double avg = 0;
			avg = (classRosterArray[i]->GetDaysToCompCrs()[0] + classRosterArray[i]->GetDaysToCompCrs()[1] + classRosterArray[i]->GetDaysToCompCrs()[2]) / 3.0;
			cout << "Student ID: " << studentID << " averages " << avg << " days in a course." << endl;
		}
	}
	
	return;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < 5; i++) {
		string contact = classRosterArray[i]->GetEmailAddr();

		bool foundat = false;
		bool foundspace = false;
		bool foundperiod = false;

		if (contact.find('@') != string::npos) {
			foundat = true;
		}

		if (contact.find('.') != string::npos) {
			foundperiod = true;
		}

		if (contact.find(' ') != string::npos) {
			foundspace = true;
		}

		if (!foundat ) {
			cout << contact << " is missing an @ symbol in the email address." << endl;
		}

		if (!foundperiod) {
			cout << contact << " is missing a period in the email address." << endl;
		}

		if (foundspace) {
			cout << contact << " has an unallowed space in the email address." << endl;
		}
	}
	cout << endl;

	return;
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << "The students in the SOFTWARE degree program are: " << endl;
	for (int i = 0; i < 5; i++) {
		DegreeProgram degreeP = classRosterArray[i]->GetDegrProg();
		if (degreeP == DegreeProgram::SOFTWARE) {
			classRosterArray[i]->Print();
		}
	}

	return;
}

Student* Roster::GetClassRosterArray(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			delete classRosterArray[i];
		}
	}
}