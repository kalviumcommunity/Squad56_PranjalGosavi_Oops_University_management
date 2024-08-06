#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_COURSE = 10;

const int MAX_STUDENT = 10;


class Student{
private:
    string name;
    int age;
    string studentID;
    string enrolled_course[MAX_COURSE];
    int courseCount;

public:
    Student(const string& name, int age, const string& studentID) : 
    name(name), age(age), studentID(studentID), courseCount(0){};


    void enrollCourse(const string& course){
        if(courseCount < MAX_COURSE){
            enrolled_course[courseCount] = course;
            courseCount++;
        }
        else{
            
            cout<<"Cannot enroll in more courses. Maximum limit reached"<<endl;
        }

    }

    void displayInfo() const {
        cout<<"Student Name: "<<name<<", Age: "<<age<<", StudentID: "<<studentID<<endl;
        cout<<"Enrolled Courses: ";

        for(int i=0;i<courseCount;i++){
            cout<<enrolled_course[i]<<" ";
        }

        cout<<endl;
    }

};

class Course{
private:

    
    string courseName;
    string courseCode;
    string enrolledStudents[MAX_STUDENT];
    int studentcount;

public:
    Course(const string& courseName, const string& courseCode ) :
    courseName(courseName), courseCode(courseCode), studentcount(0){}

    void addStudent(const string& studentID){
        if(studentcount < MAX_STUDENT){
            enrolledStudents[studentcount] = studentID;
            studentcount++;
        }

        else{
            cout<<"Connot add more students. Maximum limit reached"<<endl;
        }
    }

       void displayInfo() const {
        cout << "Course Name: " << courseName << ", Course Code: " << courseCode << endl;
        cout << "Enrolled Students: ";
        for (int i = 0; i < studentcount; i++) {
            cout << enrolledStudents[i] << " ";
        }
        cout << endl;
    }

};



