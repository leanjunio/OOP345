# Move and Copy Semantics
*Update 14.09.2018:* Updated the sample output for Move Assignment operator.

*Update 17.09.2018:* Added the missing namespace for the template parameter in the main file.

In this workshop, you are to compare move and copy operations on an object that contains a dynamically allocated array of string objects.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- implement copy semantics for a class with a resource
- implement move semantics for a class with a resource
- identify the processing-intensive operations in copy and move assignments
- retrieve data from a text file using an `ifstream` object

## Specifications
### Text Class
Design and code a class named `Text` that manages a dynamically allocated array of strings (use the class `string`). Upon instantiation, a `Text` object receives nothing or a reference to an unmodifiable string. The string holds the name of the text file that contains the records to be stored in an object of this class. If the file does not exist, the Text object assumes a safe empty state. If the file exists, the one-argument constructor allocates memory for the number of lines contained in the file and copies them into memory.

To review the syntax for reading from a text file using an `ifstream` object see the chapter in your notes entitled `Custom File Operators`. See also cplusplus.com

Your design also includes the following member functions:
- a copy constructor
- a copy assignment operator
- a move constructor
- a move assignment operator
- a destructor
- a member function named `size_t size() const` that returns the number of records of text data

Define your class and its implementation in namespace `w2`. Store your class definition in a header file named `Text.h` and your member function definitions in an implementation file named `Text.cpp`.

### Input
A text file named `gutenberg_shakespeare` is available with this lab. Make sure you include this file as a command line argument.

## main Module

```cpp
// Workshop 2 - Copy and Move Semantics
// w2.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-31
// Updated by Cornel

#include <iostream>
#include <iomanip>
#include <chrono>
#include "Text.h"
#define TIMEP(start, end) (std::chrono::duration_cast<std::chrono::nanoseconds>((end) - (begin)).count())

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        std::cout << argv[0] << ": missing file operand\n";
        return 1;
    }
    else if (argc != 2)
    {
        std::cout << argv[0] << ": too many arguments\n";
        return 2;
    }

    auto begin = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();

    {
        begin = std::chrono::high_resolution_clock::now();
        w2::Text a;
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Default Constructor "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - a.size = " << a.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
        w2::Text b(argv[1]);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Custom Constructor "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - b.size = " << b.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
        a = b;
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Copy Assignment "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - a.size = " << a.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
        a = std::move(b);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Move Assignment "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - a.size = " << a.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
        w2::Text c = a;
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Copy Constructor "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - c.size = " << c.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
        w2::Text d = std::move(a);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Move Constructor "
                  << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
                  << " - d.size = " << d.size() << std::endl;

        begin = std::chrono::high_resolution_clock::now();
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Destructor "
              << std::setw(10) << TIMEP(begin, end) << " nanoseconds"
              << std::endl;

    return 0;
}
```

### Sample output

The output of this program is based on the speed and processing power of the machine that it’s being run on. What you are looking for in the output is the following:

- Size of all the objects should be the same
- Copy operations should be slower than move operations

```cpp
Default Constructor        365 nanoseconds - a.size = 0
Custom Constructor  5081412845 nanoseconds - b.size = 124457
Copy Assignment      232443920 nanoseconds - a.size = 124457
Move Assignment      127706601 nanoseconds - a.size = 124457
Copy Constructor     227679470 nanoseconds - c.size = 124457
Move Constructor           364 nanoseconds - d.size = 124457
Destructor           256894140 nanoseconds
```