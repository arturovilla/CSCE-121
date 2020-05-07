#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "Student.h"

using namespace std;


Student::Student(string student_id, string name) : id(student_id), name(name) {} // constructor

string Student::get_id()
{
    return id;
}
string Student::get_name()
{
    return name;
}

void Student::addCourse(string course_id) //course_ids is declared in student header
{
    course_ids.push_back(course_id);
}
void Student::listCourses()//***CANT DO THIS ONE FOR NOW
{
    if(course_ids.size()==0)
    {
        cout<<"No Courses"<<endl;
    }
    else
    {
        for(int i = 0; i<course_ids.size();i++)
        {
            cout<<course_ids.at(i)<<endl;
        }
        
    }
}




