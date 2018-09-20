#ifndef _W4_MESSAGE_H
#define _W4_MESSAGE_H

#include <fstream>
#include <string>

using String = std::string;

namespace w4
{
	class Message
	{
		std::string m_Message;
		std::string m_User;
		std::string m_Tweet;
		std::string m_Reply;
		char m_Delimeter;
	public:
		Message();
		Message(String message, String user, String tweet, String reply, char delimeter);
		Message(std::ifstream& in, char c);
		~Message();
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif // !_W4_MESSAGE_H



