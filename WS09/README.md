_Attached Files_
- [SecureData.cpp](SecureData.cpp) (2.317 KB)
- [SecureData.h](SecureData.h) (725 B)
- [w9.cpp](w9.cpp) (712 B)
- [w9_text.dat](w9_text.dat) (921 B)

# Multi-Threading
In this workshop, you backup an encrypted text file of characters to a binary file, restore the encrypted data from the binary file and add multi-threading to the solution.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- process partitioned data on two or more threads
- write a set of characters to a file in binary mode
- read a set of characters from a file in binary mode
- bind a function to its arguments

## Specifications
The three source files provided for this workshop are

- `SecureData.h` — already implemented, **do not modify**
- `SecureData.cpp` — partially implemented
- `w9.cpp` — — already implemented, **do not modify**
The `SecureData` class holds text in encoded form along with the number of bytes in the text including the null terminator.

The `Cryptor` function object holds the encryption/decryption logic used by the  `SecureData` class. This object is fully implemented.

### Task 1: Binary File Access
Your first task is to complete the `backup()` and `restore()` member functions of the `SecureData` class. Your code in each case should open the binary file in the appropriate mode and throw an exception if opening fails.

For backup, your code simply writes the data to the file.

For restoration, your code deallocates the existing data, determines the number of bytes to be read, allocates memory for them, and reads the data from the file.

### Task 2: Multi-threading
Your second task is to multi-thread the conversion in the `code()` member function of the `SecureData` class.

Select a reasonable number of threads and partition the data equally amongst all of the threads. Use `std::bind` from the `functional` library to bind the converter.

## `main` Module
Do not modify the main module.

```cpp
// Workshop 9 - Multi-Threading
// w9.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Command Line: " << argv[0];
    for (int i = 1; i < argc; i++)
        cout << " " << argv[i];
    cout << endl << endl;

    if (argc != 4)
    {
        cerr << endl << "***Incorrect number of arguments***" << endl;
        return 1;
    }

    char key = argv[3][0];

    try {
        w9::SecureData sd(argv[1], key, &cout);
        sd.backup(argv[2]);

        sd.restore(argv[2], key);
        cout << sd << std::endl;

    } catch (const std::string& msg) {
        cout << msg << std::endl;
    }

    return 0;
}
```

### Sample Output
The output from your completed main program for the file contents listed above should read like:

```
Command Line: ws w9_text.dat w9_encoded.dat C

921 bytes copied from file w9_text.dat into memory (null byte added)
Data encrypted in memory

922 bytes copied from binary file w9_encoded.dat into memory.
Data decrypted in memory

Compound types are types that a programmer constructs from a language's
fundamental types and/or other compound types.  In C++11, compound types
include pointers and references to existing types, enumerations of named
constant values, arrays of objects of an existing type, classes and function
types.  C++11 clarified the difference between lvalues and rvalues and
references to each, which helped simplify many of the facilities available
in the standard library.

This chapter describes the non-function types in detail.  The description
includes a review of one-dimensional arrays in both static and dynamic memory
and shows how to allocate multi-dimensional arrays in both static and dynamic
memory.  The description of classes reviews class definitions, introduces
move-constructors and move-assignment operators and includes declarations of
special members such as bit fields, class variables and class functions.
```