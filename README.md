# Student Gradebook and Result Analyzer
**Course:** CSC-102 Programming Fundamentals 
**University:** UET Lahore, New Campus 
**Deadline:** 28th Dec 2025 

## 1. Project Overview
This project is a "Complex Computing Problem" (CCP) designed to manage student records and analyze performance. It utilizes core programming concepts including arrays, functions, structures, and file handling to create a persistent management system.

## 2. Problem Understanding & Assumptions (A9)
As per the requirement to identify ill-defined requirements, we have established the following grading policies and system constraints:

### 2.1 Grading Scale & Weightage
* **Grading System:** 4.0 GPA Scale.
* **Passing Criteria:** Minimum 50% aggregate per subject to pass.
* **Component Weightage:**
    * Quizzes: 10%
    * Assignments: 10%
    * Mid-Term: 30%
    * Final Exam: 50%

### 2.2 System Assumptions
* **Course Load:** The system handles 7 subjects (5 Theory + 2 Labs) per student.
* **Persistence:** Data is loaded from a text file at startup and saved back upon exit.

## 3. Program Design (A2, A8)
The system is built using a modular approach where interdependent modules affect the overall system accuracy.



### 3.1 Data Structures (A3)
* **struct Course**: Stores marks for quizzes, midterms, and finals, alongside calculated total marks and grades.
* **struct Student**: Stores ID, Name, an array of Course structures, and the final Semester GPA.

### 3.2 Core Functions
* `loadRecords()`: Imports data from text files at the start.
* `calculateGPA()`: Computes GPA and assigns grades based on defined criteria.
* `rankStudents()`: Sorts records from highest to lowest GPA.
* `generateReports()`: Exports topper lists and subject averages to a file.
* `updateRecords()`: Provides searching and modification functionality.

## 4. How to Run
1. Ensure `students.txt` is in the same directory as the executable.
2. Compile the program using a C++ compiler.
3. Use the menu-driven interface to manage records and generate reports.
