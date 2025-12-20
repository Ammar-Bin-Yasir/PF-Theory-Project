# Student Gradebook and Result Analyzer
[cite_start]**Course:** CSC-102 Programming Fundamentals [cite: 3]
[cite_start]**University:** UET Lahore, New Campus [cite: 1]
[cite_start]**Deadline:** 28th Dec 2025 [cite: 4]

## 1. Project Overview
[cite_start]This project is a "Complex Computing Problem" (CCP) designed to manage student records and analyze performance[cite: 2, 16]. [cite_start]It utilizes core programming concepts including arrays, functions, structures, and file handling to create a persistent management system[cite: 10, 11, 34].

## 2. Problem Understanding & Assumptions (A9)
[cite_start]As per the requirement to identify ill-defined requirements[cite: 12, 52], we have established the following grading policies and system constraints:

### 2.1 Grading Scale & Weightage
* [cite_start]**Grading System:** 4.0 GPA Scale[cite: 18, 52].
* **Passing Criteria:** Minimum 50% aggregate per subject to pass.
* **Component Weightage:**
    * Quizzes: 10%
    * Assignments: 10%
    * Mid-Term: 30%
    * Final Exam: 50%

### 2.2 System Assumptions
* [cite_start]**Course Load:** The system handles 7 subjects (5 Theory + 2 Labs) per student[cite: 17, 21].
* [cite_start]**Persistence:** Data is loaded from a text file at startup and saved back upon exit[cite: 19, 30, 31].

## 3. Program Design (A2, A8)
[cite_start]The system is built using a modular approach where interdependent modules affect the overall system accuracy[cite: 12, 52].



### 3.1 Data Structures (A3)
* [cite_start]**struct Course**: Stores marks for quizzes, midterms, and finals, alongside calculated total marks and grades[cite: 10, 21].
* [cite_start]**struct Student**: Stores ID, Name, an array of Course structures, and the final Semester GPA[cite: 21, 22].

### 3.2 Core Functions
* [cite_start]`loadRecords()`: Imports data from text files at the start[cite: 30, 35].
* [cite_start]`calculateGPA()`: Computes GPA and assigns grades based on defined criteria[cite: 22, 44].
* [cite_start]`rankStudents()`: Sorts records from highest to lowest GPA[cite: 23, 43].
* [cite_start]`generateReports()`: Exports topper lists and subject averages to a file[cite: 24, 31, 44].
* [cite_start]`updateRecords()`: Provides searching and modification functionality[cite: 28, 43].

## 4. How to Run
1. [cite_start]Ensure `students.txt` is in the same directory as the executable[cite: 30].
2. Compile the program using a C++ compiler.
3. [cite_start]Use the menu-driven interface to manage records and generate reports[cite: 18].
