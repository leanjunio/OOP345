#include <iostream>

struct Foo
{
	Foo()
	{
		std::cout << "Foo()" << std::endl;
	}
	~Foo() {std::cout << "~Foo()" << std::endl; }
	void process()
	{
		std::cout << "Processing..." << std::endl;
		throw 10;
		std::cout << "done!" << std::endl;
	}
};

class FooPtr
{
	Foo* m_theFoo = nullptr;
public:
	FooPtr(Foo* aFoo)
		: m_theFoo(aFoo)
	{
	}
	FooPtr(const Foo&) = delete;
	FooPtr& operator=(const FooPtr&) = delete;

	FooPtr(FooPtr&& other)
	{
		m_theFoo = other.m_theFoo;
		other.m_theFoo = nullptr;
	}

	FooPtr& operator=(FooPtr&& other)
	{
		if (this != &other)
		{
			delete m_theFoo;
			m_theFoo = other.m_theFoo;
			other.m_theFoo = nullptr;
		}

		return *this;
	}
	~FooPtr()
	{
		delete m_theFoo;
	}

	Foo& operator*()
	{
		return *m_theFoo;
	}

	Foo* operator->()
	{
		return m_theFoo;
	}
	
};

void bar()
{
	Foo* theFoo = new Foo();

	try
	{
		theFoo->process();
	}
	// ...
	catch (...)
	{
		delete theFoo;
		throw;
	}
		delete theFoo;
}

void foo(char* a, char* b)
{
	while (*a++ = *b++);
}
void foo(char* a)
{
	a[0] = 'A';
}

int main()
{
	char s[] = "Hello";
	int i = -1;

	while (s[++i])
		std::cout << (void*)&s[i] << " -> " << s[i] << std::endl;

	{
		char dest[10];
		foo(dest, s);
		std::cout << "===================================================" << std::endl;
		const char* it = s;
		while (*it)
		{
			std::cout << (void*)it << " -> " << *it << std::endl;		
			it++;
		}

		std::cout << dest << std::endl;
	}

	{
		std::cout << "===================================================" << std::endl;

		char s[] = "Hello";
		const char* p = "Hello";
		const char* q = "Hello";

		foo(s);
		// foo(p);

		std::cout << "p = [" << (void*)s << "]" << std::endl;
		std::cout << "q = [" << (void*)p << "]" << std::endl;
		std::cout << "s = [" << (void*)q << "]" << std::endl;
	}
	{
		try
		{
			bar();
		}
		catch (...) { std::cout << "ERROR!" << std::endl; }
	}
}