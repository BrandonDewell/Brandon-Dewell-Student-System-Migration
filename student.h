#pragma once

#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	//Mutators
	void SetStudID(string studIden);
	void SetFName(string firstName);
	void SetLName(string lastName);
	void SetEmailAddr(string email);
	void SetAge(int ageNum);
	void SetDaysCompCrs(int* daysCompCrs);
	void SetDaysCompCrsString(int* daysToCompleteCourse);
	void SetDegrProg(DegreeProgram degrProg);

	//Accessors
	string GetStudID() const;
	string GetFName() const;
	string GetLName() const;
	string GetEmailAddr() const;
	int    GetAge() const;
	int*   GetDaysToCompCrs();
	string GetDaysCompCrsString();
	DegreeProgram GetDegrProg() const;
	string GetDegrProgString() const;

	Student(string studentID, string firstName, string lastName, string email, int age, int* da, DegreeProgram degreeProgram);  //Constructor
	~Student();  //Destructor
	void Print();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int	   age;
	string days;
	int    daysToCompleteCourse[3];
	DegreeProgram degreeProgram;
};