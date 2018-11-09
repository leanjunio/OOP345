#pragma once
#include "Grade.h"
#include "Student.h"
class Grades
{
	Grade* m_Grades;
public:
	Grades();
	Grades(int NumCoursesTaken);
	~Grades();
};

