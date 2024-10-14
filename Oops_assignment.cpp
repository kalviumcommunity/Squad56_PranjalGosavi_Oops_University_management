#include <iostream>
#include <string>

using namespace std;

const int MAX_COURSES = 10;
const int MAX_STUDENTS = 10;

// Class: Person (Base class)
class Person {
protected:  // protected access to be accessible in derived classes
    string name;
    int age;

public:
    // Constructor
    Person(const string& name = "", int age = 0) : name(name), age(age) {}

    // Accessor (Getter) Methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    // Virtual function to display info
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Class: Student (Derived from Person)
class Student : public Person {
private:
    string studentID;
    string* enrolledCourses;  
    int courseCount;
    static int totalStudents; 

public:
    // Constructor
    Student(const string& name = "", int age = 0, const string& studentID = "")
        : Person(name, age), studentID(studentID), courseCount(0) {
        enrolledCourses = new string[MAX_COURSES];  
        totalStudents++;  // Increment total students count
    }

    // Destructor to free allocated memory
    ~Student() {
        delete[] enrolledCourses;  
        totalStudents--; 
    }

    // Mutator (Setter) Methods
    void setStudentID(const string& studentID) {
        this->studentID = studentID;
    }

    // Accessor (Getter) Methods
    string getStudentID() const {
        return studentID;
    }

    // Function to enroll in a course
    void enrollCourse(const string& course) {
        if (courseCount < MAX_COURSES) {
            enrolledCourses[courseCount] = course;
            courseCount++;
        } else {
            cout << "Cannot enroll in more courses. Maximum limit reached." << endl;
        }
    }

    // Overriding displayInfo from Person class
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Student ID: " << studentID << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < courseCount; i++) {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
    }

    static int getTotalStudents() {  // Static function to return total students
        return totalStudents;
    }
};

int Student::totalStudents = 0;

// Class: GraduateStudent (Derived from Student, Single Inheritance)
class GraduateStudent : public Student {
private:
    string thesisTitle;

public:
    GraduateStudent(const string& name = "", int age = 0, const string& studentID = "", const string& thesisTitle = "")
        : Student(name, age, studentID), thesisTitle(thesisTitle) {}

    void setThesisTitle(const string& thesisTitle) {
        this->thesisTitle = thesisTitle;
    }

    string getThesisTitle() const {
        return thesisTitle;
    }

    // Overriding displayInfo to show thesis title
    void displayInfo() const override {
        Student::displayInfo();
        cout << "Thesis Title: " << thesisTitle << endl;
    }
};

// Class: Course
class Course {
private:
    string courseName;
    string courseCode;
    string* enrolledStudents;  
    int studentCount;
    static int totalCourses;  

public:
    // Constructor
    Course(const string& courseName = "", const string& courseCode = "")
        : courseName(courseName), courseCode(courseCode), studentCount(0) {
        enrolledStudents = new string[MAX_STUDENTS]; 
        totalCourses++;  
    }
    
    // Destructor
    ~Course() {
        delete[] enrolledStudents;  
        totalCourses--;  
    }

    // Mutator (Setter) Methods
    void setCourseName(const string& courseName) {
        this->courseName = courseName;
    }

    void setCourseCode(const string& courseCode) {
        this->courseCode = courseCode;
    }

    // Accessor (Getter) Methods
    string getCourseName() const {
        return courseName;
    }

    string getCourseCode() const {
        return courseCode;
    }

    void addStudent(const string& studentID) {
        if (studentCount < MAX_STUDENTS) {
            enrolledStudents[studentCount] = studentID;
            studentCount++;
        } else {
            cout << "Cannot add more students. Maximum limit reached." << endl;
        }
    }

    void displayInfo() const {
        cout << "Course Name: " << courseName << ", Course Code: " << courseCode << endl;
        cout << "Enrolled Students: ";
        for (int i = 0; i < studentCount; i++) {
            cout << enrolledStudents[i] << " ";
        }
        cout << endl;
    }

    static int getTotalCourses() {
        return totalCourses;
    }
};

int Course::totalCourses = 0;

// Class: Instructor (Derived from both Person and Course - Multiple Inheritance)
class Instructor : public Person, public Course {
private:
    string instructorID;

public:
    Instructor(const string& name = "", int age = 0, const string& courseName = "", const string& courseCode = "", const string& instructorID = "")
        : Person(name, age), Course(courseName, courseCode), instructorID(instructorID) {}

    // Overriding displayInfo to include instructor's course and ID
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Instructor ID: " << instructorID << endl;
        Course::displayInfo();
    }
};

int main() {
    // Example of Student and GraduateStudent (Single Inheritance)
    GraduateStudent gradStudent("Alice", 25, "S12345", "AI and Machine Learning");
    gradStudent.enrollCourse("Data Structures");
    gradStudent.enrollCourse("Algorithms");
    gradStudent.displayInfo();

    // Example of Instructor (Multiple Inheritance)
    Instructor instructor("Dr. John", 45, "Computer Science", "CS101", "I98765");
    instructor.addStudent("S12345");
    instructor.addStudent("S67890");
    instructor.displayInfo();

    cout << "Total number of students: " << Student::getTotalStudents() << endl;
    cout << "Total number of courses: " << Course::getTotalCourses() << endl;

    return 0;
}
