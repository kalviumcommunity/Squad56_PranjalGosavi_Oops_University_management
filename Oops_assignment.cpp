#include <iostream>
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
    string* enrolledCourses;  
    int courseCount;
    static int totalStudents;  // Static variable to count total students

public:
    // Constructor
    Student(const string& name = "", int age = 0, const string& studentID = "")
        : name(name), age(age), studentID(studentID), courseCount(0) {
        enrolledCourses = new string[MAX_COURSES];  
        totalStudents++;  // Increment total students count
    }

    // Destructor to free allocated memory
    ~Student() {
        delete[] enrolledCourses;  
        totalStudents--;  // Decrement total students count
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

    // Function to display student information
    void displayInfo() const {
        cout << "Student Name: " << name << ", Age: " << age
             << ", Student ID: " << studentID << endl;
        cout << "Enrolled Courses: ";
        for (int i = 0; i < courseCount; i++) {
            cout << enrolledCourses[i] << " ";
        }
        cout << endl;
    }

    static int getTotalStudents() {  // Static function to return total students
        return totalStudents;
    }

    string getStudentID() const {
        return studentID;
    }
};

// Initialize static variable for Student class
int Student::totalStudents = 0;


// Class: Course
class Course {
private:
    string courseName;
    string courseCode;
    string* enrolledStudents;  
    int studentCount;
    static int totalCourses;  // Static variable to count total courses

public:
    // Constructor
    Course(const string& courseName = "", const string& courseCode = "")
        : courseName(courseName), courseCode(courseCode), studentCount(0) {
        enrolledStudents = new string[MAX_STUDENTS]; 
        totalCourses++;  // Increment total courses count
    }

    // Destructor to free allocated memory
    ~Course() {
        delete[] enrolledStudents;  
        totalCourses--;  // Decrement total courses count
    }

    // Function to add a student to the course
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

    static int getTotalCourses() {  // Static function to return total courses
        return totalCourses;
    }

    string getCourseCode() const {
        return courseCode;
    }
};

// Initialize static variable for Course class
int Course::totalCourses = 0;


int main() {
    // Dynamically allocate arrays of Student and Course objects
    Student* students[MAX_STUDENTS];
    Course* courses[MAX_COURSES];

    int studentCount = 0;  
    int courseCount = 0;   

    // Input for Student
    string studentName, studentID;
    int studentAge, numCourses;
    cout << "Enter student name: ";
    getline(cin, studentName);
    cout << "Enter student age: ";
    cin >> studentAge;
    cout << "Enter student ID: ";
    cin >> studentID;
    cin.ignore(); 

    // Create a new Student object and store it in the students array
    students[studentCount++] = new Student(studentName, studentAge, studentID);

    cout << "Enter number of courses to enroll: ";
    cin >> numCourses;
    cin.ignore();
    for (int i = 0; i < numCourses && i < MAX_COURSES; i++) {
        string course;
        cout << "Enter course " << i + 1 << ": ";
        getline(cin, course);
        students[0]->enrollCourse(course);
    }

    students[0]->displayInfo();

    // Input for Course
    string courseName, courseCode;
    int numStudents;
    cout << "Enter course name: ";
    getline(cin, courseName);
    cout << "Enter course code: ";
    cin >> courseCode;
    cin.ignore(); 

    // Create a new Course object and store it in the courses array
    courses[courseCount++] = new Course(courseName, courseCode);

    cout << "Enter number of students to add to the course: ";
    cin >> numStudents;
    cin.ignore(); 
    for (int i = 0; i < numStudents && i < MAX_STUDENTS; i++) {
        string studentID;
        cout << "Enter student ID " << i + 1 << ": ";
        getline(cin, studentID);
        // Add students to the first course for simplicity
        courses[0]->addStudent(studentID);
    }

    // Display course information
    courses[0]->displayInfo();

    // Display total students and total courses
    cout << "Total number of students: " << Student::getTotalStudents() << endl;
    cout << "Total number of courses: " << Course::getTotalCourses() << endl;

    // Deallocate memory
    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    for (int i = 0; i < courseCount; i++) {
        delete courses[i];
    }

    return 0;
}
