#ifndef _PAIR_H
#define _PAIR_H

template <typename A, typename B>
class Pair
{
	A m_A;
	B m_B;
public:
	Pair();
	Pair(const A&, const B&);				// sets the value of the pair
	const A& getKey() const;				// gets the value of 'A'
	const B& getValue() const;				// gets the value of 'B'
};

#endif // !_PAIR_H


