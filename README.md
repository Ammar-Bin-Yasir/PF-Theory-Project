# Student Gradebook and Result Analyzer
**Course:** CSC-102 Programming Fundamentals 
### Collaborators:
* **Ammar-Bin-Yaisr**   2025-CS-560
* **Ashna-Sami-Butt**   2025-CS-562


## 1. Project Overview
This project is a "Complex Computing Problem" (CCP) designed to manage student records and analyze performance. The app runs a menu-based program that shows the user (teacher) multiple options for different tasks. The teacher can view the current list of students in a table view and perform tasks such as updating a student's data, searching for a student from the list, sorting the student list, and viewing analytics like the pass-fail ratio and subject-wise average. Lastly, the teacher can store all the reports generated in a CSV file for later use.

## 2. Problem Understanding & Assumptions (A9)
As per the requirement to identify ill-defined requirements, we have established the following grading policies and system constraints:

### 2.1 Grading Scale & Mapping
We have adopted a standard 4.0 scale common in Pakistani Engineering Universities to convert weighted totals into Grade Points.

| Percentage | Letter Grade | Grade Points |
| :--- | :--- | :--- |
| 90% and above | A+ | 4.0 |
| 86% - 89% | A | 4.0 |
| 82% - 85% | A- | 3.7 |
| 78% - 81% | B+ | 3.3 |
| 74% - 77% | B | 3.0 |
| 70% - 73% | B- | 2.7 |
| 66% - 69% | C+ | 2.3 |
| 62% - 65% | C | 2.0 |
| 58% - 61% | C- | 1.7 |
| 54% - 57% | D+ | 1.3 |
| 50% - 53% | D | 1.0 |
| Below 50% | F | 0.0 |

### 2.2 GPA Calculation Formula
The Semester GPA (SGPA) is calculated by multiplying the Grade Points of each course by its Credit Hours, summing these "Quality Points," and dividing by the total credit hours.

$$SGPA = \frac{\sum_{i=1}^{n} (GradePoints_i \times CreditHours_i)}{\sum_{i=1}^{n} CreditHours_i}$$

### 2.3 System & CSV Assumptions
To ensure modularity and interdependence (A8), the following technical assumptions are made:
* **Course Load:** Every student record must contain marks for exactly **(User set value)** subjects and the total semester Cr.Hrs must be in the range **15-18 credit hours**.
* **Component Weightage:** Total marks **out of 100** for a course are computed as: 
  * Quizzes (2): 10%
  * Assignments: 10%
  * Mid-Term: 30%
  * Final Exam: 50%
 
 | Student_ID | Name | Math(T) | Physics(T) | PF(T) | English(T) | ICT(T) | PF_Lab(L) | ICT_Lab(L) | SGPA | Grade |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| 2025560 | Ammar Bin Yasir | 85.5 | 78.0 | 92.0 | 88.5 | 81.0 | 95.0 | 88.0 | 3.82 | A- |

> **Note on CSV headers:**
> * The first line of the file should be the column headers.
> * The **Student_ID** is the primary key "int" for every student.
> * The **Name** contains the full name of the student.
> * The last 2 columns **Grade** & **SGPA** shows the grade and the semester GPA for each student
> * All the columns in between are the **Course Name** for all the courses, and they show the weighted marks (out of 100) for every student in that course.
> * **Persistence:** The system loads these records at startup and saves updated marks back to this file.

  
* **Pass/Fail Ratio:** A student is considered "Passed" only if their SGPA is $\ge 1.0$ and they have no "F" grades in core subjects.

## 3. Program Design 
The system is built using a modular approach where interdependent modules affect the overall system accuracy.

### 3.1 Main function
The main function runs the logic of providing the UI to the user and calling other functions to manipulate the data and see results.
The flow of the Program is as follows:
* The program first initializes an array of "Student" structs to account for each student.
* Then it calls the `loadRecords()` function to read the **students.csv** file and read the data from it into the array of *student structs*
* then the program moves in a menu-based do-while loop with switch cases
* There are 8 total Cases (operations) a user can perform:
  1. Display the table of all (current) records.
  2. Search a Student based on their ID.
     2.1 Searches for a student based on their ID and then displays their table in the output window.
  3. Update Student Marks.
     3.1 Searches a student based on their ID and then gives the option to change the marks of any of the user's exams, then updates the student.csv table.
  4. Delete the Student from the table.
     4.1 Searches a student based on their ID and deletes their entire row of data, then updates the student.csv table.
  5. Sort the Student list in (ACS/DESC).
     5.1 Asks the user in what order the sort the table and then displays(updates) the sorted version of the table to the user.
  6. View Analytics & Statistics.
     * Toppers list
     * Subject-wise Average
     * Student Pass/Fail ratio
  7. Export the generated reports to a file.
     7.1 Asks the user to provide a file path to write the data to; if there exists a file there, it writes the reports to it; else, it creates a new file in that destination
  9. Save and Exit.



### 3.2 Data Structures 
* **struct Course**: Stores marks for quizzes, midterms, and finals, alongside calculated total marks and grades.
* **struct Student**: Stores ID, Name, an array of Course structures, and the final Semester GPA.

### 3.3 Core Functions
* `loadRecords()`: Imports data from text files at the start.
* `calculateGPA()`: Computes GPA and assigns grades based on defined criteria.
* `rankStudents()`: Sorts records from highest to lowest GPA.
* `generateReports()`: Exports topper lists and subject averages to a file.
* `updateRecords()`: Provides searching and modification functionality.


## 4. How to Run
1. Ensure `students.txt` is in the same directory as the executable.
2. Compile the program using a C++ compiler.
3. Use the menu-driven interface to manage records and generate reports.


## 5. Testing with Edge Cases




## 6. Sample generated reports
