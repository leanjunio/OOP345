#include <iostream>

class Foo
{
    size_t m_Count;
    short* m_Ptr;

public:
    // Overloaded constructor
    Foo(size_t cnt)
        : m_Count(cnt)
    {
        std::cout << "Foo(size_t): " << this << std::endl;
        m_Ptr = new short[cnt];
        m_Count = cnt;

        for (size_t i = 0u; i < cnt; ++i)
            m_Ptr[i] = i - 43;
    }

    // Default constructor
    Foo()
        : m_Count(0)
    {
        m_Ptr = new short[m_Count];
    }

    // Copy Constructor
    Foo(const Foo& other)
        : m_Count(other.m_Count)
    {
        std::cout << "Copy C: " << this << " from " << &other << std::endl;
        m_Ptr = new short[m_Count];

        for (size_t i =0; i < m_Count; i++)
            m_Ptr[i] = other.m_Ptr[i];
    }

    // Move Constructor
    Foo(Foo&& other)
    {
        std::cout << "Move C: " << this << " from " << &other << std::endl;
        m_Count = other.m_Count;
        m_Ptr = other.m_Ptr;            // shallow copy the address from other
        other.m_Ptr = nullptr;
    }

    // Copy assignment
    Foo& operator=(const Foo& other)
    {
        m_Count = other.m_Count;

        if (this != &other)
        {
            delete[] m_Ptr;
            m_Ptr = new short[m_Count];

            for (size_t i = 0; i < m_Count; i++)
                m_Ptr[i] = other.m_Ptr[i]; 
        }
        
        return *this;
    }

    // Move assignment operator
    Foo& operator=(Foo&& other)
    {
        if (this != &other)
        {
            m_Count = other.m_Count;
            delete[] m_Ptr;
            m_Ptr = other.m_Ptr;

            other.m_Ptr = nullptr;
        }
        return *this;
    }

    // Destructor
    ~Foo()
    {
        delete[] m_Ptr;
    }
    
};

Foo processData()
{
    Foo res = 2;
    return res;         // calls the move constructor to wherever its returning to .. (line 18)
}

int main()
{
    Foo f = 5;
    Foo x = f;          // copy constructor
    f = Foo(54);        // Move constructor since Foo(54) is now an R-value
    f = processData();  // calls the move assignment of whatever the function is returning
    std::cin.get();
}