// Name: Lean Junio
// Seneca Student ID: 019-109-123
// Seneca email: ljjunio@myseneca.ca
// Date of completion: 11/12/2018
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Workshop 8 - Smart Pointers
// Element.h
#ifndef W8_ELEMENT_H
#define W8_ELEMENT_H

#include <iomanip>
#include <string>
#include <fstream>

extern const int FWC;
extern const int FWD;
extern const int FWP;
/**
 *
 * This File defines 4 structures:
 * - ValidationException
 * - Description
 * - Price
 * - Product
 * 
 */
namespace w8
{
	// Exception Handler for Validation
	struct ValidationException : public std::exception
	{
		std::string message;
		ValidationException(std::string msg) : message(msg) {}
		~ValidationException() throw() {}
		const char *what() const throw() { return message.c_str(); }
	};

	struct Description
	{
		unsigned code;
		std::string desc;
		bool load(std::ifstream &f)
		{
			f >> code >> desc;
			return f.good();
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWC) << code
			<< std::setw(FWD) << desc
			<< std::endl;
		}
	};

	struct Price
	{
		unsigned code;
		double price;
		bool load(std::ifstream &f)
		{
			f >> code >> price;
			return f.good();
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWC) << code << std::setw(FWP)
			<< price << std::endl;
		}
	};

	struct Product
	{
		std::string desc;
		double price;
		int m_id;
		static size_t idGenerator;
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;
		Product()
		{
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    DC [" << m_id << "]" << std::endl;
		}
		Product(const std::string &str, double p)
		{
			this->desc = str;
			this->price = p;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "     C [" << m_id << "]" << std::endl;
		}
		Product(const Product &other)
		{
			this->desc = other.desc;
			this->price = other.price;
			m_id = ++Product::idGenerator;
			if (Product::Trace)
				std::cout << "    CC [" << m_id
						<< "] from [" << other.m_id << "]"
						<< std::endl;
		}
		~Product()
		{
			if (Product::Trace)
				std::cout << "    ~D [" << m_id << "]" << std::endl;
		}

		inline void validate()
		{
			std::string msg = "*** Negative prices are invalid ***";
			if (this->price < 0)
				throw msg;
		}

		void display(std::ostream &os) const
		{
			os << std::setw(FWD) << desc
			<< std::setw(FWP) << price
			<< std::endl;
		}
	};
} // namespace w8
#endif