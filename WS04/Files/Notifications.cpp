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
		: m_Messages {}
	{	
	}

	Notifications::Notifications(const Notifications & other)
		// Allow the current object to take the value of the parameter passed to the constructor
		// This constructor can be called via: `Notifications n1 = Notifications::previousN1;`
	{
		*this = other;
	}

	Notifications & Notifications::operator=(const Notifications & other)
		// Allow the current object to take the value of the parameter using the '=' operator
		// Called via: `Notifications::n1 = Notifications::n2;`
	{
		if (this != &other)
			this->m_Messages = other.m_Messages;

		return *this;
	}

	Notifications::Notifications(Notifications && other)
	{
		*this = std::move(other);
	}

	Notifications & Notifications::operator=(Notifications && other)
	{
		if (this != &other)
		{
			this->m_Messages = other.m_Messages;
			(other.m_Messages).clear();
		}

		return *this;
	}

	Notifications::~Notifications()
	{
	}
	void Notifications::operator+=(const Message & msg)
		// Pushes the passed msg parameter into the vector m_Messages
	{
		m_Messages.push_back(msg);
	}
	void Notifications::display(std::ostream & os) const
	{	
		for (Message m : m_Messages)
			m.display(os);
	}
}