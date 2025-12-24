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

	string grade;
};

struct Student
{
	int id;
	string name;

	Course subjects[TotalSubjects];

	// wieghted sum of all course points / total cr.hrs
	float sgpa;

	string finalGrade;
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






void loadRecords(Student students[])
{

}

void rankStudents(Student s[])
{

}

void loadMockData(Student students[]) {
	students[0].id = 2025560;
	students[0].name = "Ammar Bin Yasir";

	// Fill one subject for testing
	students[0].subjects[0].courseName = "PF";
	students[0].subjects[0].crHrs = 3;
	students[0].subjects[0].quiz[0] = 8;     // out of 10
	students[0].subjects[0].quiz[1] = 9;
	students[0].subjects[0].assignment = 10;
	students[0].subjects[0].mids = 25;       // out of 30
	students[0].subjects[0].finals = 40;     // out of 50

	// You would call calculateGPA() here next!

}


string getGradeLetter(float totalMarks) 
{
	if (totalMarks >= 90) return "A+";
	else if (totalMarks >= 86 && totalMarks <= 89) return "A";
	else if (totalMarks >= 82 && totalMarks <= 85) return "A-";
	else if (totalMarks >= 78 && totalMarks <= 81) return "B+";
	else if (totalMarks >= 74 && totalMarks <= 77) return "B";
	else if (totalMarks >= 70 && totalMarks <= 73) return "B-";
	else if (totalMarks >= 66 && totalMarks <= 69) return "C+";
	else if (totalMarks >=62  && totalMarks <=65 ) return "C";
	else if (totalMarks >= 58 && totalMarks <= 61) return "C-";
	else if (totalMarks >= 54 && totalMarks <= 57) return "D+";
	else if (totalMarks >= 50 && totalMarks <= 53) return "D";
	else if (totalMarks <=50) return "F";

}

void  calcuateSGPA(Student &s) 
{
	int totalCrHrs = 0;
	float totalsum = 0;
	for (int i = 0; i < 7; i++) 
	{
		totalCrHrs += s.subjects[i].crHrs;
		float gp = getGradePoint(s.subjects[i].totalMarks);
		totalsum += (gp * s.subjects[i].crHrs);
	}
	s.sgpa = totalsum / totalCrHrs;
}

void Sgrade(Student &s) 
{
	if (s.sgpa == 4.0)
		s.finalGrade = "A+";
	else if (s.sgpa <= 3.9 && s.sgpa >= 3.7)
		s.finalGrade = "A";
	else if (s.sgpa <= 3.7 && s.sgpa >= 3.3)
		s.finalGrade = "A-";
	else if (s.sgpa <= 3.3 && s.sgpa >=3.0)
		s.finalGrade = "B+";
	else if (s.sgpa <= 3.0 && s.sgpa >=2.7)
		s.finalGrade = "B";
	else if (s.sgpa <= 2.7 && s.sgpa >=2.3)
		s.finalGrade = "B-";
	else if (s.sgpa <= 2.3 && s.sgpa >=2.0)
		s.finalGrade = "C+";
	else if (s.sgpa <= 2.0 && s.sgpa >=1.7)
		s.finalGrade = "C";
	else if (s.sgpa <= 1.7 && s.sgpa >= 1.3)
		s.finalGrade = "C-";
	else if (s.sgpa <= 1.3 && s.sgpa >= 1.0)
		s.finalGrade = "D+";
	else if (s.sgpa <= 1.0 && s.sgpa >= 0.0)
		s.finalGrade = "D";
	else if (s.sgpa == 0.0)
		s.finalGrade = "F";
	

	
}




