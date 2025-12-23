#include <iostream>
#include <string>
using namespace std;

// Constants
const int TotalSubjects = 7;
const int TotalStudents = 50;


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


void loadRecords(Student student[]);


int main()
{
    // Allocated dynamic memory because stack memory was getting overload
    Student* students = new Student[TotalStudents]{};

    // Load the data from files into the structures
    loadRecords(students);
	
    cout << "=====================================================\n" 
		 << "||            Student Management System            ||\n"
		 << "=====================================================\n\n";

	int n;
	do
	{
		cout << "1. Display the table of all (current) records.\n"
			 << "2. Search a Student based on their ID.\n"
			 << "3. Update Student Marks.\n"
			 << "4. Delete Student from the table.\n"
			 << "5. Sort the Student list in (ACS/DESC).\n"
			 << "6. View Analytics & Statistics.\n"
			 << "7. Export Reports in a file.\n"
			 << "8. Save and Exit.\n";

		cin >> n;

		switch (n)
		{
			// Display the struct in an ascii art type table
			case 1:
			{
				break;
			}

			// Search and display the student based on it's ID
			case 2:
			{
				break;
			}

			// Update the Student data in the struct table
			case 3:
			{
				break;
			}

			// Delete the student records from the table
			case 4:
			{
				break;
			}

			// Sort and display the table in Ascending or Descending order
			case 5:
			{
				break;
			}

			// provide options to see analytical reports (topper list, course-wise averages, student paas fail ratio)
			case 6:
			{
				break;
			}

			// Export the reports in a text file
			case 7:
			{
				break;
			}

			// Save the existing struct in the student.csv file and Exit
			case 8:
			{
				break;
			}
		}
		

	} while (n != 8);
    
    delete[] students;

    return 0;
}

void loadRecords(Student student[])
{

}

