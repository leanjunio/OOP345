#include "Timekeeper.h"

namespace sict
{
	size_t Timekeeper::counter = 0;

	Timekeeper::Timekeeper() : 
		m_message(nullptr),
		m_units(nullptr),
		mt_start{},
		mt_end{},
		mt_duration{}
	{
	}

	void Timekeeper::recordEvent(const char *)
	{
	}

	Timekeeper::~Timekeeper()
	{
	}
}

