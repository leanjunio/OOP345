#include "Grades.h"
#include "Grade.h"

Grades::Grades()
	: m_Grades(nullptr)
{
}

Grades::Grades(int NumberCourses)
	: m_Grades(new Grade[NumberCourses])
{
}


Grades::~Grades()
{
}
