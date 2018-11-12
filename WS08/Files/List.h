// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/12/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 8 - Smart Pointers
// List.h
#ifndef W8_LIST_H
#define W8_LIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace w8
{
	/**
	 * Class List
	 * This class creates a vector of type T
	 */
	template <typename T>
	class List
	{
		std::vector<T> list;

	public:
		List() {}
		List(const char *fn)
		{
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
			while (file)
			{
				T e;
				if (e.load(file))
					list.push_back(*new T(e));
			}
		}
		size_t size() const { return list.size(); }
		const T &operator[](size_t i) const { return list[i]; }

		// TODO: Overload the += operator with a smart pointer
		//       as a second operand (second operand when used, not upon definition).
		void operator+=(const std::unique_ptr<T>& ptr)
		{
			list.push_back(*ptr);	// Push the pointer's contents into the list
		}

		// TODO: Overload the += operator with a raw pointer
		//       as a second operand.
		void operator+=(const T* ptr)
		{
			list.push_back(*ptr);	// Push the pointer's contents into the list
		}

		void display(std::ostream &os) const
		{
			os << std::fixed << std::setprecision(2);
			for (auto &e : list)
				e.display(os);
		}
	};

	template <typename T>
	std::ostream &operator<<(std::ostream &os, const List<T> &l)
	{
		l.display(os);
		return os;
	}
} // namespace w8
#endif