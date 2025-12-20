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
> * the **Student_ID** is the primary key "int" for every student.
> * the **Name** contains the full name of the student.
> * the last 2 columns **Grade** & **SGPA** shows the grade and the semester GPA for each student
> * all the columns in between are the **Course Name** for all the courses, and they show the weighted marks (out of 100) for every student in that course.
> * **Persistence:** The system loads these records at startup and saves updated marks back to this file.

  
* **Pass/Fail Ratio:** A student is considered "Passed" only if their SGPA is $\ge 1.0$ and they have no "F" grades in core subjects.

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
