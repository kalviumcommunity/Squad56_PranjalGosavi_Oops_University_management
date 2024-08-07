# University Management System 🏫
## Overview
The University Management System is a simple console-based application written in C++ that demonstrates the use of Object-Oriented Programming (OOP) principles. The system allows for the management of student enrollments and course assignments. It includes features for creating student profiles, enrolling students in courses, and managing course information.

## Features ✏️
Student Management:

Create a student profile with name, age, and student ID.
Enroll students in multiple courses.
Display student information, including enrolled courses.

Course Management:

Create a course with a course name and code.
Add students to the course.
Display course information, including enrolled students.
Implementation Details
Classes
Person (Base Class)

A base class providing common attributes and methods for all persons in the system. This class includes the following members:
name: Name of the person.
age: Age of the person.
id: Unique identifier (student ID or professor ID).
Student (Derived Class from Person)

Manages student-specific information and operations.

* Data Members:
string enrolledCourses[MAX_COURSES]: Array to store courses the student is enrolled in.
int courseCount: Counter to keep track of the number of enrolled courses.

* Member Functions:
enrollCourse(const string& course): Enrolls the student in a course.
displayInfo() const: Displays student information.
Course

Manages course-specific information and operations.
Data Members:
string courseName: Name of the course.
string courseCode: Unique course code.
string enrolledStudents[MAX_STUDENTS]: Array to store student IDs of enrolled students.
int studentCount: Counter to keep track of the number of enrolled students.
Member Functions:
addStudent(const string& studentID): Adds a student to the course.
displayInfo() const: Displays course information.

## Usage 
Compile the Program:
To compile the program, use a C++ compiler like g++. In the command line, navigate to the directory containing the source code and run:

css
Copy code
g++ -o UniversityManagementSystem main.cpp
Replace main.cpp with the name of your C++ source file if it's different.

* Run the Program:
After compiling, run the executable:

Copy code
./UniversityManagementSystem

* Input Data:

The program will prompt you to enter student and course information. Follow the on-screen prompts to input data.
Enter the student's name, age, ID, and the number of courses they are enrolling in.
Enter course names as required.
Enter the course's name and code, then specify the number of students and their IDs.

* Display Information:

The program will display the entered information, including details of students and courses.
Limitations
The maximum number of courses a student can enroll in and the maximum number of students a course can have are both limited by the constants MAX_COURSES and MAX_STUDENTS, respectively.
The current implementation does not include data persistence; data is lost when the program terminates.
Error handling is basic and does not cover all edge cases.


## Future Improvements🌟
Implement data persistence using file handling or a database.
Improve the user interface and error handling.
Expand the system to include additional features, such as a professor management module or more detailed course descriptions.
