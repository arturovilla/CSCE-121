#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include "School.h"
#include "AttendanceRecord.h"
#include "Course.h"
#include "Date.h"
using namespace std;

void School::addStudents(string filename) {
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
    while (!ifs.eof()) {
        string line;
        getline(ifs, line);
        istringstream ss(line);
        string uin;
        getline(ss, uin, ',');
        string name;
        getline(ss, name);
        if (!ss.fail()) {
            students.push_back(Student(uin, name));
        }
    }
}



void School::addCourses(string filename)
{
    {
        ifstream ifs(filename);
        if (!ifs.is_open()) {
            cout << "Unable to open file: " << filename << endl;
            return;
        }
        while (!ifs.eof()) {
            string line;
            getline(ifs, line);
            
            istringstream ss(line);
            
            string id;
            getline(ss, id, ',');
            //time part
            //start hr
            string starthr;
            getline(ss,starthr,':');
            int hr = 0;
            stringstream num(starthr);
            num>>hr;
            
            //get minute
            string startmin;
            getline(ss,startmin,',');
            int min = 0;
            stringstream num1(startmin);
            num1>>min;
            //end hour
            string endhr;
            getline(ss,endhr,':');
            int ehr = 0;
            stringstream num2(endhr);
            num2>>ehr;
            
            //end min
            string endmin;
            getline(ss,endmin,',');
            int emin = 0 ;
            stringstream num3(endmin);
            num3>>emin;
            //courname
            string coursename;
            getline(ss, coursename);
            
            //Date(int hour, int min, int sec=0);
            
            Date start(hr,min);
            Date end(ehr,emin);
            if (!ss.fail()) {
                courses.push_back(Course(id,coursename,start,end));
            }
        }
        
    }
}

void School::addAttendanceData(std::string filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open())
    {
        cout << "Unable to open file: " << filename << endl;
        return;
    }
    
    while (!ifs.eof())
    {
        string line;
        getline(ifs, line);
        istringstream ss(line);
        ///////////////////////////////////////////////////
        string year;
        getline(ss, year, '-');
        int swipeyear = 0;
        stringstream yearw(year);
        yearw >> swipeyear;
        ///////////////////////////////////////////////////
        string month;
        getline(ss, month, '-');
        int swipemonth = 0;
        stringstream monthw(month);
        monthw >> swipemonth;
        ///////////////////////////////////////////////////
        string day;
        getline(ss, day, ' ');
        int swipeday = 0;
        stringstream dayw(day);
        dayw >> swipeday;
        ///////////////////////////////////////////////////
        string hour;
        getline(ss, hour, ':');
        int swipehour = 0;
        stringstream hourw(hour);
        hourw >> swipehour;
        //////////////////////////////////////////////////
        string min;
        getline(ss, min, ':');
        int swipemin = 0;
        stringstream minw(min);
        minw >> swipemin;
        //////////////////////////////////////////////////
        string sec;
        getline(ss, sec, ',');
        int swipesec = 0;
        stringstream secw(sec);
        secw >> swipesec;
        Date date(swipeyear, swipemonth, swipeday, swipehour, swipemin, swipesec);
        /////////////////////////////////////////////////
        string courseid;
        getline(ss, courseid, ',');
        ////////////////////////////////////////////////
        string uin;
        getline(ss, uin);
        AttendanceRecord ar(courseid, uin, date);
        
        if (!ss.fail()) {
            for(int i = 0; i < courses.size(); i++)
            {
                if(courses.at(i).getID() == courseid)
                {
                    courses.at(i).addAttendanceRecord(ar);
                }
            }
        }
    }
}

///////////////////////////////////////////////////////
void School::listCourses()
{
    if(courses.size() == 0){ // if vector size is 0
        cout << "No Courses" << endl;
    }
    else
    {
        for(int i = 0; i < courses.size(); i++)
        {
            cout << courses.at(i).getID() << "," << setw(2) << setfill('0')<< courses.at(i).getStartTime().getHour() << ":" << setw(2) << setfill('0')
            << courses.at(i).getStartTime().getMin() << "," << setw(2) << setfill('0')
            << courses.at(i).getEndTime().getHour() << ":" << setw(2) << setfill('0')
            << courses.at(i).getEndTime().getMin() << ","
            << courses.at(i).getTitle() << endl;
        }
    }
}

///////////////////////////////////////////////////////
void School::listStudents()
{
    if(students.size() == 0)
    {
        cout << "No Students" << endl;
    }
    else
    {
        for(int i = 0; i < students.size(); i++)
        {
            cout << students.at(i).get_id() << ","<< students.at(i).get_name() << endl;
        }
    }
}
///////////////////////////////////////////////////////

void School::outputCourseAttendance(string course_id)
{
    for(int i = 0; i < courses.size(); i++)
    {
        if(courses.at(i).getID() == course_id)
        {
            courses.at(i).outputAttendance();
        }
    }
}
///////////////////////////////////////////////////////


void School::outputStudentAttendance(string student_id, string course_id)
{
    for(int i = 0; i < courses.size(); i++)
    {
        if(courses.at(i).getID() == course_id)
        {
            for(int j = 0; j < students.size(); j++)
            {
                if(students.at(j).get_id() == student_id)
                {
                    courses.at(i).outputAttendance(student_id);
                }
            }
        }
    }
}


