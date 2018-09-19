#ifndef _W4_MESSAGE_H
#define _W4_MESSAGE_H

#include <fstream>
#include <string>

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
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream& os) const;
		~Message();
	};
}

#endif // !_W4_MESSAGE_H



