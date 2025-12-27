# Student Gradebook and Result Analyzer

**Course:** CSC-102 — Programming Fundamentals  

## Contributors
- **Ammar Bin Yaisr** (2025-CS-560)  
- **Ashna Sami Butt** (2025-CS-562)

---

## 1. Project Overview

The **Student Gradebook and Result Analyzer** is a menu-driven console application developed as a **Complex Computing Problem (CCP)**. The system is designed to manage student academic records and perform performance analysis for instructors.

The application allows a teacher to:
- View student records in a structured tabular format  
- Search, update, delete, and sort student data  
- Analyze academic performance using statistical reports  
- Export processed results and analytics to a CSV file for persistence and future use  

---

## 2. Problem Understanding and Assumptions (A9)

Due to partially ill-defined requirements, the following grading policies and system constraints were explicitly defined to ensure correctness and consistency.

### 2.1 Grading Scale and Mapping

A standard **4.0 GPA scale**, commonly used in Pakistani engineering universities, is used to convert percentage scores into Grade Points.

| Percentage Range | Letter Grade | Grade Points |
|------------------|--------------|--------------|
| 90% and above | A+ | 4.0 |
| 86% – 89% | A | 3.9 |
| 82% – 85% | A- | 3.7 |
| 78% – 81% | B+ | 3.3 |
| 74% – 77% | B | 3.0 |
| 70% – 73% | B- | 2.7 |
| 66% – 69% | C+ | 2.3 |
| 62% – 65% | C | 2.0 |
| 58% – 61% | C- | 1.7 |
| 54% – 57% | D+ | 1.3 |
| 50% – 53% | D | 1.0 |
| Below 50% | F | 0.0 |

---

### 2.2 GPA Calculation Formula

The **Semester Grade Point Average (SGPA)** is calculated using weighted credit hours:

$$SGPA = \frac{\sum_{i=1}^{n} (GradePoints_i \times CreditHours_i)}{\sum_{i=1}^{n} CreditHours_i}$$

---

### 2.3 System and CSV Assumptions (A8)

To ensure modularity and interdependence, the following assumptions were established:

- **Course Load:**  
  Each student must be enrolled in exactly **(user-defined)** number of subjects, with a total semester load between **15–18 credit hours**.

- **Component Weightage:**  
  Each course is evaluated out of **100 marks**, distributed as:
  - Quizzes (2): 10%  
  - Assignments: 10%  
  - Mid-Term Exam: 30%  
  - Final Exam: 50%

#### Sample CSV Structure

| Student_ID | Name | Math(T) | Physics(T) | PF(T) | English(T) | ICT(T) | PF_Lab(L) | ICT_Lab(L) | SGPA | Grade |
|------------|------|---------|------------|-------|-------------|--------|------------|-------------|------|--------|
| 2025560 | Ammar Bin Yasir | 85.5 | 78.0 | 92.0 | 88.5 | 81.0 | 95.0 | 88.0 | 3.82 | A- |

**CSV File Specifications**
- The first row contains column headers  
- `Student_ID` serves as the primary key (integer)  
- `Name` contains the student’s full name  
- Intermediate columns represent course names with weighted marks  
- Final columns store **SGPA** and **Grade**  
- The file is loaded at program startup and updated upon any modification  

- **Pass/Fail Criteria:**  
  A student is considered **passed** if:
  - SGPA ≥ 1.0  
  - No **F** grade in any core subject  

---

## 3. Program Design

The application follows a **modular design**, where each component contributes to overall system accuracy and reliability.

### 3.1 Main Program Flow

The `main()` function provides a menu-driven user interface and coordinates all program operations.

**Execution Flow:**
1. Initialize an array of `Student` structures  
2. Load student data from `students.csv` using `loadRecords()`  
3. Enter a `do-while` loop with menu-based options  
4. Perform selected operations via switch cases  

**Available Operations:**
1. Display all student records  
2. Search for a student by ID  
3. Update student marks  
4. Delete a student record  
5. Sort records (ascending or descending order)  
6. View analytics and statistics  
   - Topper list  
   - Subject-wise averages  
   - Pass/Fail ratio  
7. Export reports to a user-specified file path  
8. Save changes and exit  

---

### 3.2 Data Structures

- **`struct Course`**  
  Stores assessment components, total marks, and assigned grade.

- **`struct Student`**  
  Stores Student ID, Name, an array of `Course` structures, and computed SGPA.

---

### 3.3 Core Functions
**File Operations**
-`saveDataToFile()` — Serializes the current array of student objects into a structured CSV file for long-term storage.

-`loadDataFromFile()` — Populates the program's data structures by reading student records and grades from an existing CSV file.

-`saveReportToFile()` — Exports a formatted academic performance report to an external text file for printing or distribution.

**Display and Reporting**
-`displayStudents()` — Iterates through the student list to provide a summary view of all enrolled students.

-`displayStudentProfile()` — Displays a detailed view of a specific student's personal information and individual course scores.

-`reportGeneration()` — Orchestrates the creation of comprehensive academic summaries, including averages and top performers.

**Data Management**
-`sortStudents()` — Reorders the student records based on specific criteria in either ascending or descending order.

**Academic Logic & Calculations**
-`calculateStudentResults()` — Triggers the comprehensive calculation logic for total marks, grade points, and SGPA for a specific student.

-`courseTotalMarks()` — Sums up weighted assessments (assignments, exams, etc.) to determine the final score for a single course.

-`getGradePoint()` — Maps a numerical course score to a standardized grade point value (e.g., 3.7).

-`getGradeLetter()` — Assigns the appropriate alphabetical grade (e.g., "B+") based on total marks earned in a course.

-`calculateSGPA()` — Computes the Semester Grade Point Average by weighting grade points against course credit hours.

-`getSemesterGrade()` — Determines the final academic standing or descriptive grade based on the calculated SGPA.

**Utilities & Analytics**
-`formatFloat()` — A helper utility that rounds and converts floating-point numbers into strings with specific decimal precision.

-`printrow()` — A UI helper that generates consistent horizontal dividers and borders for tabular terminal output.

-`printCell()` — Handles the alignment and padding of data within a specific column width for table consistency.

-`topper()` — Identifies the highest-scoring student in a specific subject and returns both their score and index.

-`subjectAverage()` — Calculates the mean score across all students for a specific course or assessment.

-`passFailRatio()` — Computes the number of students who met the passing criteria versus those who did not for a specific subject.

---

## 4. How to Run the Program

1. Place `students.txt` in the same directory as the executable  
2. Compile the source code using any standard C++ compiler  
3. Run the program and interact using the menu-driven interface  

---

## 5. Testing and Edge Cases

- Empty file handling  
- Invalid student ID input  
- Boundary GPA values (e.g., 1.0, 4.0)  
- Duplicate IDs prevention  
- Sorting with identical GPAs  

---

## 6. Sample Generated Reports

*(Included in exported CSV files)*
