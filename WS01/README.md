## From One Translation Unit to Another
In this workshop, you implement aspects of linkage, storage duration, namespaces, guards, and operating system interfaces.

### Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the ability to
- link to a variable in another translation unit
- declare a local variable that lasts the lifetime of the program
- guard a class definition from repetition
- define a class within its own namespace
- pass arguments to program from the command line

Specifications
This workshop consists of three modules:
- `w1`
- `process`
- `CString`

#### CString Module
Write the header and implementation files for a class named `CString`. Wrap your header file in a conditional macro that guards against repeated use. Embed your class definition and its implementation in a namespace named `w1`.

Include in your class definition:
- a constant definition of the number of characters to be stored by an object of your class (private member)—`MAX`.
- a constructor that receives the address of a C-style null-terminated string and stores the first `MAX` characters of the string. Initialize `MAX` to the value of `STORED` (see below). Check for receipt of the null address. Store an empty string in that case.
- a member query named `display()` that receives a reference to an `ostream` object and displays the string as stored in your `CString` object
- a helper non-friend insertion operator that inserts the stored string into the left `ostream` operand. This operator prefaces the string with the number of the insertion and increments that number

Do not use the `string` class of the standard library in this workshop. Use the `cstring` functions.

Include in your implementation file:
- a definition of a global variable initialized to the number of characters stored by an object of your class—`STORED`.

#### process Module
Write the header and implementation files for a function named `process`. Your function receives the address of a C-style null-terminated string and a std::ostream reference.

The `process` module uses an object of your CString class to store a possibly truncated version of the string. Leave your prototype and function definition in the global namespace. In your definition:
- construct a `CString` object from the string received
- insert the `CString` object into the std::ostream object and terminate with a newline

#### main Module
Update the `main()` module to include an external variable to access the max number of characters stored by your `CString` object. Print the max number of characters to the `std::ostream` object.

```cpp
// Workshop 1 - Linkage, Storage Duration, Namespaces,
// and OS Interface
// w1.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <iostream>
#include <fstream>
#include "process.h"

using namespace std;

// TODO: Declare (without defining) the global variable
// you have defined in CString.cpp

int main(int argc, char* argv[])
{
    cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << ' ';
    }
    if (argc < 2)
    {
        cout << "\nInsufficient number of arguments\n";
        return 1;
    }

    // TODO: Add code here that will print out max characters
    // stored by your CString object

    for (int i = 1; i < argc; i++)
    {
        process(argv[i], cout);
    }

    return 0;
}
```

#### Sample Output
```
Command Line: ...\ws.exe oop345 dps941
Maximum number of characters stored: 3
0: oop
1: dps
```