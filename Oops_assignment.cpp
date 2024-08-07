#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_COURSES = 10;
const int MAX_STUDENTS = 10;

// Class: Student
class Student {
private:
    string name;
    int age;
    string studentID;
    string enrolledCourses[MAX_COURSES];
    int courseCount;

public:
    
    Student(const string& name, int age, const string& studentID)
        : name(name), age(age), studentID(studentID), courseCount(0) {}

    // Function to set student information (uses this pointer)
    void setInfo(const string& name, int age, const string& studentID) {
        this->name = name;        // Using this pointer to access member variable
        this->age = age;
        this->studentID = studentID;
    }

    void enrollCourse(const string& course) {
        if (courseCount < MAX_COURSES) {
            enrolledCourses[courseCount] = course;
            courseCount++;
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    void displayInfo() const {
        cout << "Student Name: " << name << ", Age: " << age
             << ", Student ID: " << studentID << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < courseCount; i++) {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
    }
};

// Class: Course
class Course {
private:
    string courseName;
    string courseCode;
    string enrolledStudents[MAX_STUDENTS];
    int studentCount;

public:
    // Constructor
    Course(const string& courseName, const string& courseCode)
        : courseName(courseName), courseCode(courseCode), studentCount(0) {}

    void addStudent(const string& studentID) {
        if (studentCount < MAX_STUDENTS) {
            enrolledStudents[studentCount] = studentID;
            studentCount++;
        } else {
            cout << "Cannot add more students. Maximum limit reached." << endl;
        }
    }

    // Function to display course information
    void displayInfo() const {
        cout << "Course Name: " << courseName << ", Course Code: " << courseCode << endl;
        cout << "Enrolled Students: ";
        for (int i = 0; i < studentCount; i++) {
            cout << enrolledStudents[i] << " ";
        }
        cout << endl;
    }
};

int main(){

};

