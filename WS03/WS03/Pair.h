#ifndef _PAIR_H
#define _PAIR_H

template <typename A, typename B>
class Pair
{
	A m_A;
	B m_B;
public:
	Pair();
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


