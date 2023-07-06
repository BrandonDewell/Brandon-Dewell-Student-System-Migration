#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
	cout << "Course Title: \t \t \t C867 - Scripting and Programming Applications" << endl << "Programming Language used: \t C++" << endl;
	cout << "WGU student ID: \t \t 001478703" << endl << "Student name: \t \t \t Brandon Dewell" << endl << endl;

	Roster classRoster;

	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Brandon,Dewell,bdewel2@wgu.edu,41,30,42,47,SOFTWARE"
	};

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	cout << "List of all students: " << endl;
	classRoster.printAll();

	cout << "List of invalid email addresses: " << endl;
	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.GetClassRosterArray(i)->GetStudID());
	}
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;

	cout << "Removing student ID A3: " << endl;
	classRoster.remove("A3");
	
	classRoster.printAll();
	
	cout << "Removing student ID A3 again: " << endl;
	classRoster.remove("A3");  //Prints message showing student ID A3 was already removed.

	return 0;
}