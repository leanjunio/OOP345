#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{
	Notifications::Notifications()
		: p_arrAddresses{nullptr}
		, m_maxNumAddresses{0}
		, m_numCurrentlyStoredAddresses{0}
	{
	}

	Notifications::Notifications(const Notifications& other)
	{
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& other)
	{
		if (this != &other)
		{
			delete[] p_arrAddresses;

			m_maxNumAddresses = other.m_maxNumAddresses;
			m_numCurrentlyStoredAddresses = other.m_numCurrentlyStoredAddresses;

			for (int i = 0; i < other.m_numCurrentlyStoredAddresses; i++)
				p_arrAddresses[i] = other.p_arrAddresses[i];
		}
		return *this;
	}
	Notifications::Notifications(Notifications&& other)
	{
		*this = std::move(other);
	}
	Notifications& Notifications::operator=(Notifications&& other)
	{
		if (this != &other)
		{
			// delete[] p_arrAddresses;

			p_arrAddresses = other.p_arrAddresses;
			m_maxNumAddresses = other.m_maxNumAddresses;
			m_numCurrentlyStoredAddresses = other.m_numCurrentlyStoredAddresses;

			other.p_arrAddresses = { nullptr };
			other.m_maxNumAddresses = { 0 };
			other.m_numCurrentlyStoredAddresses = { 0 };
		}
		return *this;
	}
	Notifications::~Notifications()
	{
		delete[] p_arrAddresses;
		p_arrAddresses = { nullptr };
	}
	Notifications::Notifications(int maxNumberOfElementsInAggregation)
	{
		if (maxNumberOfElementsInAggregation > 0)
		{
			p_arrAddresses = new const Message*[maxNumberOfElementsInAggregation];
			m_maxNumAddresses = maxNumberOfElementsInAggregation;
			m_numCurrentlyStoredAddresses = { 0 };
		}
		else
			*this = Notifications();
	}
	Notifications& Notifications::operator+=(const Message& messagedToAdd)
	{
		bool space_available = m_numCurrentlyStoredAddresses < m_maxNumAddresses;

		if (!messagedToAdd.empty() && space_available)
		{
			p_arrAddresses[m_numCurrentlyStoredAddresses] = &messagedToAdd;	// store the address
			++m_numCurrentlyStoredAddresses;
		}

		return *this;
	}
	Notifications& Notifications::operator-=(const Message& messageToRemove)
	{
		for (int i = 0; i < m_numCurrentlyStoredAddresses; i++)
		{
			bool address_found = p_arrAddresses[i] == &messageToRemove;

			if (address_found)
			{
				p_arrAddresses[i] = { nullptr };

				// move all subsequent addresses left
				for (int x = i; x < m_numCurrentlyStoredAddresses - 1; ++x)
					p_arrAddresses[x] = p_arrAddresses[x + 1];

				p_arrAddresses[m_numCurrentlyStoredAddresses - 1] = { nullptr };
			}
		}

		m_numCurrentlyStoredAddresses--;

		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (int i = 0; i < m_numCurrentlyStoredAddresses; i++)
			(*p_arrAddresses[i]).display(os);
	}
	size_t Notifications::size() const
	{
		return m_numCurrentlyStoredAddresses;
	}
	std::ostream & operator<<(std::ostream & os, Notifications & n)
	{
		n.display(os);
		return os;
	}
}
