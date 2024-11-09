#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_COURSES = 10;

// Interface: Person
class Person {
public:
    virtual void displayInfo() const = 0;  // Pure virtual method for displaying information
    virtual ~Person() = default;
};

// Abstract Class: CourseType
class CourseType {
public:
    virtual string getCourseInfo() const = 0;  // Pure virtual function
    virtual ~CourseType() = default;
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
    virtual ~CourseManagerInterface() = default;
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

// Class: Student (Implements Person, uses CourseManager for course management)
class Student : public Person {
private:
    string name;
    int age;
    string studentID;
    CourseManager courseManager;

public:
    Student(const string& name, int age, const string& studentID)
        : name(name), age(age), studentID(studentID) {}

    void enrollCourse(CourseType* course) {
        courseManager.enrollCourse(course);
    }

    void displayInfo() const override {
        cout << "Student Name: " << name << ", Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
        courseManager.displayCourses();
    }
};

// Class: Instructor (Implements Person, does not use CourseManager)
class Instructor : public Person {
private:
    string name;
    int age;
    string instructorID;

public:
    Instructor(const string& name, int age, const string& instructorID)
        : name(name), age(age), instructorID(instructorID) {}

    void displayInfo() const override {
        cout << "Instructor Name: " << name << ", Age: " << age << endl;
        cout << "Instructor ID: " << instructorID << endl;
    }
};

int main() {
    // Using Student class as an instance of Person (Liskov Substitution Principle)
    Person* person1 = new Student("Alice", 20, "S12345");
    person1->displayInfo();
    delete person1;

    // Using Instructor class as an instance of Person (Liskov Substitution Principle)
    Person* person2 = new Instructor("Dr. John", 45, "I98765");
    person2->displayInfo();
    delete person2;

    return 0;
}
