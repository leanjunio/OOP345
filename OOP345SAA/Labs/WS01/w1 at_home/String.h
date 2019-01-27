#ifndef _SICT_STRING_H
#define _SICT_STRING_H

namespace sict
{
	class String
	{
		char *m_string;		// C-style null terminated string of any length
	public:
		String(const char*);
		void display(std::ostream&) const;
	};
	
	std::ostream& operator<<(std::ostream&, String&);
	
}

#endif // !_SICT_STRING_H


