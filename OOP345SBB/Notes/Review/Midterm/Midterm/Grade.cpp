#include "Grade.h"



Grade::Grade()
	: m_NumericGrade(0.0)
	, m_Subject{}
{
}

Grade::Grade(double NumericGrade, std::string Subject)
	: m_NumericGrade(NumericGrade)
	, m_Subject(Subject)
{
}
