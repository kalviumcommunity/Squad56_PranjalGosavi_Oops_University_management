#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_COURSES = 10;
const int MAX_STUDENTS = 10;

// Abstract Class: Person (Base class)
class Person {
protected:
    string name;
    int age;

public:
    // Default constructor
    Person() : name("Unknown"), age(0) {}

    // Constructor with name and age
    Person(const string& name, int age) : name(name), age(age) {}

    // Pure virtual function to enforce derived classes to implement it
    virtual void displayInfo() const = 0;  // Abstract method

    // Destructor should be virtual in a base class
    virtual ~Person() {}
};

// Class: CourseManager (Handles course enrollment)
class CourseManager {
private:
    vector<string> enrolledCourses;

public:
    // Enroll in a course
    void enrollCourse(const string& course) {
        if (enrolledCourses.size() < MAX_COURSES) {
            enrolledCourses.push_back(course);
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    // Display enrolled courses
    void displayCourses() const {
        cout << "Enrolled Courses: ";
        for (const auto& course : enrolledCourses) {
            cout << course << " ";
        }
        cout << endl;
    }
};

// Class: Student (Derived from Person)
class Student : public Person {
private:
    string studentID;
    CourseManager courseManager;  // Uses CourseManager for course handling

public:
    // Constructor
    Student(const string& name = "", int age = 0, const string& studentID = "")
        : Person(name, age), studentID(studentID) {}

    // Enroll in a course via CourseManager
    void enrollCourse(const string& course) {
        courseManager.enrollCourse(course);
    }

    // Override the pure virtual function in Person
    void displayInfo() const override {
        cout << "Student Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        courseManager.displayCourses();  // Display courses via CourseManager
    }
};

// Class: Instructor (Derived from Person)
class Instructor : public Person {
private:
    string instructorID;

public:
    // Constructor
    Instructor(const string& name = "", int age = 0, const string& instructorID = "")
        : Person(name, age), instructorID(instructorID) {}

    // Override the pure virtual function in Person
    void displayInfo() const override {
        cout << "Instructor Name: " << name << ", Age: " << age << endl;
        cout << "Instructor ID: " << instructorID << endl;
    }
};

int main() {
    // Example of Student (Derived from Person)
    Student student1("Alice", 20, "S12345");
    student1.enrollCourse("Data Structures");
    student1.enrollCourse("Algorithms");
    student1.displayInfo();  // Calls the overridden displayInfo method in Student

    // Example of Instructor (Derived from Person)
    Instructor instructor1("Dr. John", 45, "I98765");
    instructor1.displayInfo();  // Calls the overridden displayInfo method in Instructor

    return 0;
}
