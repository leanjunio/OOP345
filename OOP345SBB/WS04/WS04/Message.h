// Name: Lean Junio
// Seneca Student ID: 019109123
// Seneca email: ljjunio@myseneca.ca	
// Date of completion: 10/1/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef _W4_MESSAGE_H
#define _W4_MESSAGE_H

#include <fstream>
#include <string>

using String = std::string;

namespace w4
{
	class Message
	{
		String m_User;
		String m_Tweet;
		String m_Reply;
		static int m_Count;
	public:
		Message();
		Message(String user, String tweet, String reply);
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream& os) const;
		int getCount() const;

		String getReply() const;
	};
}

#endif // !_W4_MESSAGE_H



