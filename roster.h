#pragma once

#include <string>
#include "student.h"

using namespace std;

class Roster {
public:
	void parse(string studentData);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	Student* GetClassRosterArray(int index);
	~Roster();
	
private:
	Student* classRosterArray[5];
	int craIndex = 0;
};