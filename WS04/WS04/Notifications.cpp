// Name: Lean Junio
// Seneca Student ID: 019109123
// Seneca email: ljjunio@myseneca.ca	
// Date of completion: 10/1/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include <vector>
#include <algorithm>
#include "Notifications.h"
#include "Message.h"

namespace w4
{
	Notifications::Notifications()
		: m_pMessages(nullptr)
	{	
	}

	Notifications::Notifications(const Notifications& other)
	{
		*this = other;
	}

	Notifications& Notifications::operator=(const Notifications& other)
		// Allow the current object to take the value of the parameter using the '=' operator
		// Called via: `Notifications::n1 = Notifications::n2;`
	{
		if (this != &other)
		{
			delete[] m_pMessages;			
			m_pMessages = new Message[other.m_pMessages->getCount()];

			for (int i = 0; i < other.m_pMessages->getCount(); ++i)
				m_pMessages[i] = other.m_pMessages[i];
		}

		return *this;
	}

	Notifications::Notifications(Notifications && other)
	{
		*this = std::move(other);
	}

	Notifications& Notifications::operator=(Notifications&& other)
	{
		if (this != &other)
		{
			m_pMessages = other.m_pMessages;

			delete[] other.m_pMessages;
			other.m_pMessages = nullptr;
		}

		return *this;
	}

	Notifications::~Notifications()
	{
		delete[] m_pMessages;
		m_pMessages = nullptr;
	}
	void Notifications::operator+=(const Message & msg)
		// Pushes the passed msg parameter into the vector m_Messages
	{
		Message* m_ppMessage = nullptr;
		m_ppMessage = new Message[m_pMessages->getCount() + 1];

		for ()
	}
	void Notifications::display(std::ostream & os) const
	{	
		for (Message m : m_pMessages)
			m.display(os);
	}
	int Notifications::getCount() const
	{
		for (int i = 0; i < m_pMessages->getCount(); ++i)
		{

		}
	}
}