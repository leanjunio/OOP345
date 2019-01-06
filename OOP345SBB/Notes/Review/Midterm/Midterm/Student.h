#pragma once
#include <string>
#include "Grades.h"
#include "Name.h"
class Student
{
	int GetCoursesTaken() const;
public:
	Student();
	Student(int StudentNumber, int CoursesTaken, const std::string& FirstName, const std::string& LastName);
	~Student();
private:
	int m_StudentNumber;
	int m_CoursesTaken;
	Name m_Name;
	Grades m_Grades;
};

