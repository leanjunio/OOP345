# Lambda Expressions
In this workshop, you convert the grades earned by students in a course to letter values using Seneca’s grading scale.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- use a lambda expression to define an operation on a set of data values
- prevent the copying, moving and assigning of an object
- throw and report an exception

Specifications
This workshop reads a file containing student numbers and grades and converts the grades to letter values using the following scale:

| Grade Range | Letter Grade |
| ------------|:------------:|
| 90-100      |	A+           |
| 80-89	      | A            |
| 75-79	      | B+           |
| 70-74	      | B            |
| 65-69	      | C+           |
| 60-64	      | C            |
| 55-59	      | D+           |
| 50-54	      | D            |
| 0-49	      | F            |

Decimal values round to nearest integer.

## Letter Enumeration
Design and code a scoped set of enumeration constants named `Letter` that identify the letter values for the grades in a course.

Include in your design, a template function that converts each enumeration constant into a C-style null-terminated string. The function receives an unmodifiable reference to one of the enumeration constants and returns the address of string that represents that constant.

Enclose your design in the `sict`. Save your design in a file named `Letter.h`.

## Grades Class
Design and code a class named `Grades` that holds the grades for all students in a course.

Upon instantiation, a `Grades` object receives the address of a C-style null-terminated string that contains the name of the file holding the grade information for all students in a course. The object allocates memory dynamically and stores this information. Each file record (row) contains one student number and a grade, which may include a decimal value. If the object cannot open the file, the constructor throws an exception with a suitable message.

Your design includes the following template member function:
- `void displayGrades(std::ostream&, F) const` — receives a reference to the output stream object and the address of the expression to be used in determining the letter grade. Your function displays the student number, the student grade and the letter equivalent (using the template function in `Letter.h`).

Your design prohibits copying, moving and assigning of a `Grades` object.

Store your class definition in a header file named `Grades.h`. Store your special function definitions in an implementation file named `Grades.cpp`.

## Main Module
Complete coding the `main` function by
- defining the lambda expression (letter) that converts a numeric grade to its letter equivalent
HINT: You should be using the letter enumeration and template function created in `Letter.h`
- adding the code to report an exception if any has been thrown

```cpp
// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    if (argc == 1) {
        std::cerr << "\n*** Insufficient number of arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 1;
    }
    else if (argc != 2) {
        std::cerr << "\n*** Too many arguments ***\n";
        std::cerr << "Usage: " << argv[0] << " fileName \n";
        return 2;
    }

    //TODO: Update the main functions as per the specifications here
    grades.displayGrades(std::cout, letter);

    return 0;
}
```
## Sample Output

```
Command Line: ws w5_grades.dat
   1022342 67.40 C+
   1024567 73.50 B
   2031456 79.30 B+
   6032144 53.50 D
   1053250 92.10 A+
   3026721 86.50 A
   7420134 62.30 C
   9762314 58.70 D+
```