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

    // Mutator (Setter) Methods
    void setName(const string& name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setStudentID(const string& studentID) {
        this->studentID = studentID;
    }

    // Accessor (Getter) Methods
    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

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
    static int totalCourses;  

public:
    Course(const string& courseName = "", const string& courseCode = "")
        : courseName(courseName), courseCode(courseCode), studentCount(0) {
        enrolledStudents = new string[MAX_STUDENTS]; 
        totalCourses++;  
    }

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

    static int getTotalCourses() {  // Static function to return total courses
        return totalCourses;
    }
};

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

    students[studentCount] = new Student();
    students[studentCount]->setName(studentName);
    students[studentCount]->setAge(studentAge);
    students[studentCount]->setStudentID(studentID);
    studentCount++;

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

    courses[courseCount] = new Course();
    courses[courseCount]->setCourseName(courseName);
    courses[courseCount]->setCourseCode(courseCode);
    courseCount++;

    cout << "Enter number of students to add to the course: ";
    cin >> numStudents;
    cin.ignore(); 
    for (int i = 0; i < numStudents && i < MAX_STUDENTS; i++) {
        string studentID;
        cout << "Enter student ID " << i + 1 << ": ";
        getline(cin, studentID);
        courses[0]->addStudent(studentID);
    }

    courses[0]->displayInfo();

    cout << "Total number of students: " << Student::getTotalStudents() << endl;
    cout << "Total number of courses: " << Course::getTotalCourses() << endl;

    // Cleanup dynamically allocated memory
    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    for (int i = 0; i < courseCount; i++) {
        delete courses[i];
    }

    return 0;
}
