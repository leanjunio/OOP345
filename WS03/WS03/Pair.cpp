#include "Pair.h"

template <typename A, typename B>
Pair::Pair() 
{
}

template<typename A, typename B>
Pair<A, B>::Pair(const A &a, const B &b)
	: m_A{a}
	, m_B{b}
{
}

template<typename A, typename B>
const A & Pair<A, B>::getKey() const
{
	return this->m_A;
}

template<typename A, typename B>
const B & Pair<A, B>::getValue() const
{
	return this->m_B;
}


