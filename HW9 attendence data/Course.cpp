#include <iostream>
#include <fstream>
#include <string>
#include "Course.h"
#include "Date.h"
#include "AttendanceRecord.h"
#include <iomanip>
//#include "School.h"
//using namespace std;
//

//
//
///*
// std::string id;
// std::string title;
// Date startTime;
// Date endTime;
// */
//
//
//Course::Course(string id, string title, Date startTime, Date endTime) :  id(id), title(title), startTime(startTime),endTime(endTime) {}
//



using namespace std;

Course::Course(string id, string title, Date startTime, Date endTime)
: id(id), title(title), startTime(startTime), endTime(endTime) {}

string Course::getID()
{
    return id;
    
}
string Course::getTitle()
{
    return title;
    
}

Date Course::getStartTime()
{
    return startTime;
    
}
Date Course::getEndTime()
{
    return endTime;
    
}

void Course::addAttendanceRecord(AttendanceRecord ar)
{
    if(ar.getDate() >= startTime && ar.getDate() <= endTime)
    {
        attendanceRecords.push_back(ar);
    }
}
void Course::outputAttendance()
{
    if(attendanceRecords.size() == 0)
    { // if size is empty
        cout << "No Records";
    }
    for(int i = 0; i < attendanceRecords.size(); i++)
    {
        cout << attendanceRecords.at(i).getDate().getMonth() << "/"
        << attendanceRecords.at(i).getDate().getDay() << "/"
        << attendanceRecords.at(i).getDate().getYear() << " " << setw(2) << setfill('0')
        << attendanceRecords.at(i).getDate().getHour() << ":" << setw(2) << setfill('0')
        << attendanceRecords.at(i).getDate().getMin() << ":" << setw(2) << setfill('0')
        << attendanceRecords.at(i).getDate().getSec() << ","
        << attendanceRecords.at(i).getCourseID()<< ","
        << attendanceRecords.at(i).getStudentID()<<endl;
    }
}
void Course::outputAttendance(string student_id)
{
    bool size = false;
    if(attendanceRecords.empty())
    {
        cout << "No Records";
    }
    
    else
    {
        //cout << attendanceRecords.size()<<endl;
        
        for(int i = 0; i < attendanceRecords.size(); i++)
        {
            if( attendanceRecords.at(i).getStudentID() == student_id)
            {
                size = true; // set size as valid
                cout << attendanceRecords.at(i).getDate().getMonth() << "/"
                << attendanceRecords.at(i).getDate().getDay() << "/"
                << attendanceRecords.at(i).getDate().getYear() << " " << setw(2) << setfill('0')
                << attendanceRecords.at(i).getDate().getHour() << ":" << setw(2) << setfill('0')
                << attendanceRecords.at(i).getDate().getMin() << ":" << setw(2) << setfill('0')
                << attendanceRecords.at(i).getDate().getSec() << ","
                << attendanceRecords.at(i).getCourseID() << ","
                << attendanceRecords.at(i).getStudentID()<< endl;
            }
        }
        
        if(size == false)
        { // if size is empty
            cout << "No Records" << endl;
        }
    }
}

