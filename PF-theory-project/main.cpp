#include <iostream>
#include <string>
#include <iomanip> 
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

// Constants
const int TotalSubjects = 8;
const int TotalStudents = 20;
static string header_row;

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
void saveDataToFile(Student students[], const string& filename = "data.csv");
void loadDataFromFile(Student students[], const string& filename = "data.csv");
void loadMockData(Student students[]);

void displayStudents(Student students[]);
void displayStudentProfile(const Student& s);

void sortStudents(Student students[], bool ascending = true);

void calculateStudentResults(Student& s);
float courseTotalMarks(const Course& c);
float getGradePoint(float totalMarks);
string getGradeLetter(float totalMarks);
float calculateSGPA(const Student& s);
string getSemesterGrade(float sgpa);

string formatFloat(float value, int precision);
void printrow(int col,int colWidth, bool newline = true, bool plus = true);
void printCell(const string& data,int cellWidth);


int main()
{
	// Heap allocation for large array
	Student* students = new Student[TotalStudents]{};

	// 1. Load Data
	loadDataFromFile(students, "data.csv");

	for (int i = 0; i < TotalStudents; i++)
	{
		calculateStudentResults(students[i]);
	}
	cout << "=====================================================\n"
		<< "||            Student Management System            ||\n"
		<< "=====================================================\n\n";

	int n;
	do
	{
		cout << "\n--- Main Menu ---\n"
			<< "1. Display the table of all (current) records.\n"
			<< "2. Search a Student based on their ID.\n"
			<< "3. Update Student Marks.\n"
			<< "4. Sort the Student list in (ACS/DESC).\n"
			<< "5. View Analytics & Statistics.\n"
			<< "6. Export Reports in a file.\n"
			<< "7. Save and Exit.\n"
			<< "Select Option: ";
		cin >> n;

        switch (n)
        {
        case 1:
        {
            displayStudents(students);
            break;
        }
        case 2:
        {
            int id, index;
            bool found = false;
            cout << "Enter the id of the Student you want to search: ";
            cin >> id;
            for (static int i = 0; i < TotalStudents; i++)
            {
                if (students[i].id == id)
                {
                    found = true;
                    index = i;
                    break;
                }
            }
            if (!found)
                cout << "Student not found.\nInvalid Student id";

            displayStudentProfile(students[index]);

            break;
        }
        case 3:
        {
            int id, index;
            bool found = false;
            cout << "Enter the id of the Student you want to update: ";
            cin >> id;
            for (static int i = 0; i < TotalStudents; i++)
            {
                if (students[i].id == id)
                {
                    found = true;
                    index = i;
                    break;
                }
            }
            if (!found)
                cout << "Student not found.\nInvalid Student id";


			int subject, choice;
			cout << "Select which Subject you want to update.\n";
			for (int i = 0; i < TotalSubjects; i++) cout << (i + 1) << ". " << students[index].subjects[i].courseName << "\n";
			cin >> subject;

			subject--;

			Course& s = students[index].subjects[subject];
			cout << "Select which marks you want to update.\n1.Quiz1\n2.Quiz2\n3.Assignment\n4.Mids\n5.Finals\n";
			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					float marks;
					while (true)
					{
						cout << "Enter Updated marks (0-10): ";
						cin >> marks;
						if (marks >= 0.0 && marks <= 10.0)
							break;  
					}
					s.quiz[0] = marks;
					break;
				}
				case 2:
				{
					float marks;
					while (true)
					{
						cout << "Enter Updated marks (0-10): ";
						cin >> marks;
						if (marks >= 0.0 && marks <= 10.0)
							break;
					}
					s.quiz[1] = marks;
					break;
				}
				case 3:
				{
					float marks;
					while (true)
					{
						cout << "Enter Updated marks (0-10): ";
						cin >> marks;
						if (marks >= 0.0 && marks <= 10.0)
							break;
					}
					s.assignment = marks;
					break;
				}
				case 4:
				{
					float marks;
					while (true)
					{
						cout << "Enter Updated marks (0-30): ";
						cin >> marks;
						if (marks >= 0.0 && marks <= 30.0)
							break;
					}
					s.mids = marks;
					break;
				}
				case 5:
				{
					float marks;
					while (true)
					{
						cout << "Enter Updated marks (0-50): ";
						cin >> marks;
						if (marks >= 0.0 && marks <= 50.0)
							break;
					}
					s.finals = marks;
					break;
				}
			}
			saveDataToFile(students);
			calculateStudentResults(students[index]);
			displayStudents(students);
			break;
		}
		case 4:
		{
			int option;
			while (true) 
			{
				cout << "1. Sort in ascending order\n"
					<< "2. Sort in descending order\n";
				cin >> option;
				if (option == 1 || option == 2)
					break;
			}
			string file;
			while (true)
			{
				cout << "Enter the file name in to store the sorted data to.\n";
				cin >> file;
				if (file.ends_with(".txt") || file.ends_with(".csv"))
					break;
				else
					cout << "file not supported.\nsupported formats (\".txt\", \".csv\")\n";
			}

			sortStudents(students, option == 1 ? 1 : 0);
			displayStudents(students);
			saveDataToFile(students, file);
			break;
		}
		case 5:
			break;
		case 6:
			break;
		case 7:
			cout << "Saving and Exiting...\n";
			break;
		default:
			cout << "Invalid option. Please try again.\n";
		}

	} while (n != 7);

	delete[] students;
	return 0;
}


// File handling functions
void loadDataFromFile(Student students[], const string& filename)
{
	// Open the file
	ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Error opening file: " << filename << endl;
		return;
	}

	string line;
	int studentIndex = 0;

	// Separate the headers
	getline(file, header_row);

	while (getline(file, line) && studentIndex < TotalStudents)
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
}
void saveDataToFile(Student students[], const string& filename)
{
	ofstream file(filename);
	if (!file.is_open())
	{
		cerr << "Error opening file for writing: " << filename << endl;
		return;
	}

	// Write headers
	file << header_row << endl;

	// Write student data to the file
	for (int i = 0; i < TotalStudents; i++)
	{
		const Student& s = students[i];
		file << s.id << "," << s.name << ",";

		for (int j = 0; j < TotalSubjects; j++)
		{
			const Course& sub = s.subjects[j];
			file << sub.courseName << "," << sub.crHrs << "," << sub.quiz[0] << "," << sub.quiz[1] << ","
				<< sub.assignment << "," << sub.mids << "," << sub.finals << ",";
		}
		file << endl;
	}

	file.close();
	cout << "Data saved successfully to: " << filename << endl;
}


// Calculation functions
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

// Display Functions
void displayStudents(Student students[])
{
	int maxNameLength = 0;
	for (int i = 0; i < TotalStudents; i++)
		maxNameLength = max(maxNameLength, static_cast<int>(students[i].name.length()));
	printrow(1, 4, false);
	printrow(1, maxNameLength, false, false);
	printrow(TotalSubjects + 2, 8, true, false);
	cout << "|";
	printCell("ID", 4);
	printCell("Name", maxNameLength);
	for (int i = 0; i < TotalSubjects; i++)
	{
		printCell(students[0].subjects[i].courseName, 8);

	}
	printCell("SGPA", 8);
	printCell("Grade", 8);
	cout << endl;
	printrow(1, 4, false, true);
	printrow(1, maxNameLength, false, false);
	printrow(TotalSubjects + 2, 8, true, false);
	cout << fixed << setprecision(2);

	for (int i = 0; i < TotalStudents; i++)
	{
		cout << "|";
		printCell(to_string(students[i].id), 4);
		printCell(students[i].name, maxNameLength);

		for (int j = 0; j < TotalSubjects; j++)
		{

			printCell(formatFloat(students[i].subjects[j].totalMarks, 2), 8);
		}

		printCell(formatFloat(students[i].sgpa, 2), 8);
		printCell(students[i].finalGrade, 8);
		cout << endl;
	}
	printrow(1, 4, false, true);
	printrow(1, maxNameLength, false, false);
	printrow(TotalSubjects + 2, 8, true, false);
}
void displayStudentProfile(const Student& s)
{

    //Top Header Info
    cout << string(100, '-') << endl;

    cout << "| Name: " << setw(91) << left << s.name << "|" << endl;
    cout << "| ID: " << setw(93) << left << s.id << "|" << endl;

    //Table Headers using Helper functions
    printrow(9, 10, true, true);
    cout << "|";
    printCell("Course", 10);
    printCell("Quiz 1", 10);
    printCell("Quiz 2", 10);
    printCell("Assign.", 10);
    printCell("Mids", 10);
    printCell("Finals", 10);
    printCell("Total", 10);
    printCell("CGPA", 10);
    printCell("Grade", 10);
    cout << endl;
    printrow(9, 10, true, true);

    //Course Data Row
    for (int j = 0; j < TotalSubjects; j++)
    {
        if (s.subjects[j].crHrs > 0) {
            cout << "|";
            printCell(s.subjects[j].courseName, 10);
            printCell(formatFloat(s.subjects[j].quiz[0], 2), 10);
            printCell(formatFloat(s.subjects[j].quiz[1], 2), 10);
            printCell(formatFloat(s.subjects[j].assignment, 2), 10);
            printCell(formatFloat(s.subjects[j].mids, 2), 10);
            printCell(formatFloat(s.subjects[j].finals, 2), 10);
            printCell(formatFloat(s.subjects[j].totalMarks, 2), 10);
            printCell(formatFloat(getGradePoint(s.subjects[j].totalMarks), 2), 10);
            printCell(s.subjects[j].coursegrade, 10);
            cout << endl;
        }
    }
        printrow(9, 10, true, true);
        cout << "|";
        printCell("", 10);
        printCell("", 10);
        printCell("", 10);
        printCell("", 10);
        printCell("", 10);
        printCell("", 10);
        printCell("", 10);
		printCell(formatFloat(s.sgpa, 2), 10);
        printCell(s.finalGrade, 10);
        cout << endl;
		printrow(9, 10, true, true);
		return;
}




// Utility/feature Functions
void sortStudents(Student students[], bool ascending)
{
	for (int i = 0; i < TotalStudents - 1; i++)
	{
		for (int j = 0; j < TotalStudents - i - 1; j++)
		{
			bool condition = ascending ? (students[j].sgpa > students[j + 1].sgpa) : (students[j].sgpa < students[j + 1].sgpa);
			if (condition)
			{
				swap(students[j], students[j + 1]);
			}
		}
	}
}




// Helper Functions
void printrow(int col,int colWidth,bool newline, bool plus) 
{
	 if(plus) cout << "+";

	for (int i = 0; i < col; i++)
	{
		cout << string(colWidth, '-') << "+";
	}
	if (newline) cout << endl;
}
void printCell(const string& data,int cellWidth)
{
	int len = static_cast<int>(data.length());
	cout << left << setw(cellWidth) << data << "|";
	return;
}
string formatFloat(float value, int precision = 2)
{
	stringstream ss;
	ss << fixed << setprecision(precision) << value;
	return ss.str();
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