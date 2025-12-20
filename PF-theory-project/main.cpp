#include <iostream>
#include <string>
using namespace std;

// Constants
const int TotalSubjects = 7;



struct Course
{
	string courseName;
	int crHrs;

	float quiz[2], assignment, mids, finals;

	// total wieghted marks out of 100
	float totalMarks;

	char grade[2];
};

struct Student
{
	int id;
	string name;

	Course subjects[TotalSubjects];

	// wieghted sum of all course points / total cr.hrs
	float sgpa;

	char finalGrade[2];
};





int main()
{


	return 0;
}