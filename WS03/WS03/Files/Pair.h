// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: September 18, 2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _PAIR_H
#define _PAIR_H

template <typename A, typename B>
class Pair
{
	A m_A;
	B m_B;
public:
	Pair()
		: m_A {}
		, m_B {}
	{
	}
	Pair(const A& a, const B& b)
		: m_A{ a }
		, m_B{ b }
	{
	}

	const A& getKey() const				// gets the value of 'A'
	{
		return m_A;
	}
	const B& getValue() const				// gets the value of 'B'
	{
		return m_B;
	}
};

#endif // !_PAIR_H


