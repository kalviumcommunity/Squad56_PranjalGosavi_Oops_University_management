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
    Person() : name("Unknown"), age(0) {}
    Person(const string& name, int age) : name(name), age(age) {}
    virtual void displayInfo() const = 0;  // Abstract method
    virtual ~Person() {}
};

// Abstract Class: CourseType (Base class for various course types)
class CourseType {
public:
    virtual string getCourseInfo() const = 0;  // Pure virtual function
    virtual ~CourseType() {}
};

// Derived Course Type: Regular Course
class RegularCourse : public CourseType {
private:
    string courseName;

public:
    RegularCourse(const string& name) : courseName(name) {}
    string getCourseInfo() const override {
        return "Regular Course: " + courseName;
    }
};

// Derived Course Type: Online Course
class OnlineCourse : public CourseType {
private:
    string courseName;

public:
    OnlineCourse(const string& name) : courseName(name) {}
    string getCourseInfo() const override {
        return "Online Course: " + courseName;
    }
};

// Interface for Course Management
class CourseManagerInterface {
public:
    virtual void enrollCourse(CourseType* course) = 0;
    virtual void displayCourses() const = 0;
    virtual ~CourseManagerInterface() {}
};

// Class: CourseManager (Handles course enrollment)
class CourseManager : public CourseManagerInterface {
private:
    vector<CourseType*> enrolledCourses;

public:
    void enrollCourse(CourseType* course) override {
        if (enrolledCourses.size() < MAX_COURSES) {
            enrolledCourses.push_back(course);
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    void displayCourses() const override {
        cout << "Enrolled Courses: ";
        for (const auto& course : enrolledCourses) {
            cout << course->getCourseInfo() << " ";
        }
        cout << endl;
    }

    ~CourseManager() {
        for (auto course : enrolledCourses) {
            delete course;
        }
    }
};

// Class: Student (Derived from Person)
class Student : public Person {
private:
    string studentID;
    CourseManagerInterface* courseManager;

public:
    Student(const string& name = "", int age = 0, const string& studentID = "")
        : Person(name, age), studentID(studentID), courseManager(new CourseManager) {}

    void enrollCourse(CourseType* course) {
        courseManager->enrollCourse(course);
    }

    void displayInfo() const override {
        cout << "Student Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        courseManager->displayCourses();
    }

    ~Student() {
        delete courseManager;
    }
};

// Class: Instructor (Derived from Person)
class Instructor : public Person {
private:
    string instructorID;

public:
    Instructor(const string& name = "", int age = 0, const string& instructorID = "")
        : Person(name, age), instructorID(instructorID) {}

    void displayInfo() const override {
        cout << "Instructor Name: " << name << ", Age: " << age << endl;
        cout << "Instructor ID: " << instructorID << endl;
    }
};

int main() {
    Student student1("Alice", 20, "S12345");
    student1.enrollCourse(new RegularCourse("Data Structures"));
    student1.enrollCourse(new OnlineCourse("Algorithms"));
    student1.displayInfo();

    Instructor instructor1("Dr. John", 45, "I98765");
    instructor1.displayInfo();

    return 0;
}
