#include <iostream>
#include <string>

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

// Class: Student (Derived from Person)
class Student : public Person {
private:
    string studentID;
    string* enrolledCourses;
    int courseCount;

public:
    // Constructor
    Student(const string& name = "", int age = 0, const string& studentID = "")
        : Person(name, age), studentID(studentID), courseCount(0) {
        enrolledCourses = new string[MAX_COURSES];
    }

    ~Student() {
        delete[] enrolledCourses;
    }

    void enrollCourse(const string& course) {
        if (courseCount < MAX_COURSES) {
            enrolledCourses[courseCount] = course;
            courseCount++;
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    // Override the pure virtual function in Person
    void displayInfo() const override {
        cout << "Student Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < courseCount; i++) {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
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
    // Abstract class cannot be instantiated directly
    // Person p1; // This will cause an error

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
