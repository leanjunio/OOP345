#include "Timekeeper.h"

namespace sict
{
	size_t Timekeeper::counter = 0;

	Timekeeper::Timekeeper()
	{
	}

	void Timekeeper::start()
	{
		std::chrono::system_clock::now();
	}

	void Timekeeper::recordEvent(const char *description)
	{
	}

	Timekeeper::~Timekeeper()
	{
	}
}

