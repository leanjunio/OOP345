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
		String m_User;
		String m_Tweet;
		String m_Reply;
	public:
		Message();
		Message(String user, String tweet, String reply);
		Message(std::ifstream& in, char c);
		~Message();
		bool empty() const;
		void display(std::ostream& os) const;
	};
}

#endif // !_W4_MESSAGE_H



