#ifndef _W4_MESSAGE_H
#define _W4_MESSAGE_H

#include <fstream>
#include <string>

using String = std::string;

namespace w4
{

	class Message
	{
		static int indexer;
		std::string m_User;
		std::string m_Tweet;
		std::string m_Reply;
	public:
		Message();
		Message(String user, String tweet, String reply);
		Message(std::ifstream& in, char c);
		~Message();
		bool empty() const;
		void display(std::ostream& os) const;
	};

	String readNthLine(std::ifstream& in, int N);
}

#endif // !_W4_MESSAGE_H



