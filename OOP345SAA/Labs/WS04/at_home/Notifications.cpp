#include <iostream>
#include <utility>
#include "Notifications.h"

namespace sict
{
	Notifications::Notifications()
		: pp_arrAddresses{nullptr}
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
			delete[] pp_arrAddresses;

			m_maxNumAddresses = other.m_maxNumAddresses;
			m_numCurrentlyStoredAddresses = other.m_numCurrentlyStoredAddresses;

			for (int i = 0; i < other.m_numCurrentlyStoredAddresses; i++)
			{
				pp_arrAddresses[i] = other.pp_arrAddresses[i];
			}
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
			delete[] pp_arrAddresses;

			pp_arrAddresses = other.pp_arrAddresses;
			m_maxNumAddresses = other.m_maxNumAddresses;
			m_numCurrentlyStoredAddresses = other.m_numCurrentlyStoredAddresses;

			other.pp_arrAddresses = { nullptr };
			other.m_maxNumAddresses = { 0 };
			other.m_numCurrentlyStoredAddresses = { 0 };
		}
		return *this;
	}
	Notifications::~Notifications()
	{
		delete[] pp_arrAddresses;
		pp_arrAddresses = { nullptr };
	}
	Notifications::Notifications(int maxNumberOfElementsInAggregation)
	{
		if (maxNumberOfElementsInAggregation > 0)
		{
			*pp_arrAddresses = new Message[maxNumberOfElementsInAggregation];
		}
		else
		{
			*this = Notifications();
		}
	}
	Notifications& Notifications::operator+=(const Message& msg)
	{
		if (!msg.empty() && m_numCurrentlyStoredAddresses < m_maxNumAddresses)
		{
			pp_arrAddresses[m_numCurrentlyStoredAddresses + 1] = &msg;	// store the address
		}

		return *this;
	}
	Notifications& Notifications::operator-=(const Message& msg)
	{
		for (size_t i = 0; i < m_numCurrentlyStoredAddresses; i++)
		{
			if (pp_arrAddresses[i] == &msg)
			{
				pp_arrAddresses = { nullptr };
			}
		}

		return *this;
	}
	void Notifications::display(std::ostream& os) const
	{
		for (size_t i = 0; i < m_numCurrentlyStoredAddresses; i++)
		{
			os << pp_arrAddresses[i];
		}
	}
	size_t Notifications::size() const
	{
		return size_t(m_numCurrentlyStoredAddresses);
	}
	std::ostream & operator<<(std::ostream & os, Notifications & n)
	{
		n.display(os);
		return os;
	}
}
