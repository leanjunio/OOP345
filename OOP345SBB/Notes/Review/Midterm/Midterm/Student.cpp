#include "Student.h"



int Student::GetCoursesTaken() const
{
	return m_CoursesTaken;
}

Student::Student()
	: m_StudentNumber(0)
	, m_CoursesTaken(0)
	, m_Name{}
	, m_Grades{}
{
}

Student::Student(int StudentNumber, int CoursesTaken, const std::string& FirstName, const std::string& LastName)
	: m_StudentNumber(StudentNumber)
	, m_CoursesTaken(CoursesTaken)
	, m_Name{FirstName, LastName}
	, m_Grades{m_CoursesTaken}
{
}


Student::~Student()
{
}
