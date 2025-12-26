#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>
#include <sstream>

using namespace std;

// Constants
const int TotalSubjects = 8;
const int TotalStudents = 20;

struct Course
{
    string courseName;
    int crHrs;
    float quiz[2], assignment, mids, finals;

    // total weighted marks out of 100
    float totalMarks;
    string coursegrade;
};

struct Student
{
    int id;
    string name;
    Course subjects[TotalSubjects];

    // weighted sum of all course points / total cr.hrs
    float sgpa;
    string finalGrade;
};

// Function Prototypes
void loadMockData(Student students[]);
void loadDataFromFile(Student students[], const string& filename);
void calculateStudentResults(Student& s);
float courseTotalMarks(const Course& c);
float getGradePoint(float totalMarks);
string getGradeLetter(float totalMarks);
float calculateSGPA(const Student& s);
string getSemesterGrade(float sgpa);


int main()
{
    // Heap allocation for large array
    Student* students = new Student[TotalStudents]{};

    // 1. Load Data
	loadDataFromFile(students, "data.csv");

    calculateStudentResults(students[0]);

    cout << "\n\n=====================================================\n"
        << "||            Student Management System            ||\n"
        << "=====================================================\n\n";

    int n;
    do
    {
        cout << "\n--- Main Menu ---\n"
            << "1. Display the table of all (current) records.\n"
            << "2. Search a Student based on their ID.\n"
            << "3. Update Student Marks.\n"
            << "4. Delete Student from the table.\n"
            << "5. Sort the Student list in (ACS/DESC).\n"
            << "6. View Analytics & Statistics.\n"
            << "7. Export Reports in a file.\n"
            << "8. Save and Exit.\n"
            << "Select Option: ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            cout << "Saving and Exiting...\n";
            break;
        default:
            cout << "Invalid option. Please try again.\n";
        }

    } while (n != 8);

    delete[] students;
    return 0;
}



// Function to Calculate all the results of a Student
void calculateStudentResults(Student& s)
{
    // Populate the Course array
    for (int i = 0; i < TotalSubjects; i++)
    {
        if (s.subjects[i].crHrs > 0)
        {
            s.subjects[i].totalMarks = courseTotalMarks(s.subjects[i]);
            s.subjects[i].coursegrade = getGradeLetter(s.subjects[i].totalMarks);
        }
    }

	// Calculate SGPA and Final Grade
    s.sgpa = calculateSGPA(s);
    s.finalGrade = getSemesterGrade(s.sgpa);
}

// Uses the individual test scores to calculate total weighted marks out of 100
float courseTotalMarks(const Course& c)
{
    
    float total = 0.0f;
    float quizTotal = c.quiz[0] + c.quiz[1]; 

    total += (quizTotal / 20.0f) * 10.0f; 
    total += (c.assignment / 10.0f) * 10.0f; 
    total += (c.mids / 30.0f) * 30.0f;       
    total += (c.finals / 50.0f) * 50.0f;     

    return total;
}

// Calculate SGPA based on the courses taken by the student
float calculateSGPA(const Student& s)
{
    int totalCrHrs = 0;
    float coursePoints = 0.0f;

    for (int i = 0; i < TotalSubjects; i++)
    {
        if (s.subjects[i].crHrs > 0) 
        {
            totalCrHrs += s.subjects[i].crHrs;

            float gp = getGradePoint(s.subjects[i].totalMarks);

            coursePoints += (gp * s.subjects[i].crHrs);
        }
    }

      
    if (totalCrHrs == 0) return 0.0f;

    return coursePoints / totalCrHrs;
}


float getGradePoint(float totalMarks)
{
    if (totalMarks >= 90) return 4.0f;
    else if (totalMarks >= 86) return 3.9f; 
    else if (totalMarks >= 82) return 3.7f; 
    else if (totalMarks >= 78) return 3.3f; 
    else if (totalMarks >= 74) return 3.0f; 
    else if (totalMarks >= 70) return 2.7f; 
    else if (totalMarks >= 66) return 2.3f; 
    else if (totalMarks >= 62) return 2.0f; 
    else if (totalMarks >= 58) return 1.7f; 
    else if (totalMarks >= 54) return 1.3f; 
    else if (totalMarks >= 50) return 1.0f; 
    else return 0.0f; 
}

string getGradeLetter(float totalMarks)
{
    if (totalMarks >= 90) return "A+";
    else if (totalMarks >= 86) return "A";
    else if (totalMarks >= 82) return "A-";
    else if (totalMarks >= 78) return "B+";
    else if (totalMarks >= 74) return "B";
    else if (totalMarks >= 70) return "B-";
    else if (totalMarks >= 66) return "C+";
    else if (totalMarks >= 62) return "C";
    else if (totalMarks >= 58) return "C-";
    else if (totalMarks >= 54) return "D+";
    else if (totalMarks >= 50) return "D";
    else return "F";
}

string getSemesterGrade(float sgpa)
{
    if (sgpa >= 4.0f) return "A+";
    else if (sgpa >= 3.9f) return "A";
    else if (sgpa >= 3.7f) return "A-";
    else if (sgpa >= 3.3f) return "B+";
    else if (sgpa >= 3.0f) return "B";
    else if (sgpa >= 2.7f) return "B-";
    else if (sgpa >= 2.3f) return "C+";
    else if (sgpa >= 2.0f) return "C";
    else if (sgpa >= 1.7f) return "C-";
    else if (sgpa >= 1.3f) return "D+";
    else if (sgpa >= 1.0f) return "D"; 
    else if (sgpa >= 0.0f) return "F";
	else return "N/A";
}



void loadMockData(Student students[])
{
    
    students[0].id = 2025560;
    students[0].name = "Ammar Bin Yasir";

    // Setup Subject 1: PF
    students[0].subjects[0].courseName = "PF";
    students[0].subjects[0].crHrs = 3;
    students[0].subjects[0].quiz[0] = 8;
    students[0].subjects[0].quiz[1] = 9;
    students[0].subjects[0].assignment = 10;
    students[0].subjects[0].mids = 25;
    students[0].subjects[0].finals = 40;

}


void loadDataFromFile(Student students[], const string& filename)
{
	// Open the file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filename << endl;
        return;
    }
    else
    {
        cout << "File opened successfully: " << filename << endl;
	}


    string line, headers;
    int studentIndex = 0;

	cout << "Loading data from file...\n";

    // Separate the headers
	getline(file, headers);

    while (getline(file, line) && studentIndex < TotalStudents )
    {
		// Makes the line into a stream (the same mechanism as cin and cout uses) so we can use << and >> operators on the string
        stringstream ss(line);

        Student& s = students[studentIndex];

        // ID
		ss >> s.id;
		// Skip the comma
		ss.ignore();
        
        // Name
        getline(ss, s.name, ',');

		// Subjects: (PF, PF_crHrs, PF_quiz1, PF_quiz2, PF_assignment, PF_mids, PF_finals, ...)
        for (int i = 0; i < TotalSubjects; i++)
        {
            getline(ss, s.subjects[i].courseName, ',');

            ss >> s.subjects[i].crHrs;
            ss.ignore();

            ss >> s.subjects[i].quiz[0];
            ss.ignore();

            ss >> s.subjects[i].quiz[1];
            ss.ignore();

            ss >> s.subjects[i].assignment;
            ss.ignore();

            ss >> s.subjects[i].mids;
            ss.ignore();

            ss >> s.subjects[i].finals;
            ss.ignore();
        }
        studentIndex++;
    }
    file.close();

	cout << "Data loading completed. Total students loaded: " << studentIndex << endl;
}