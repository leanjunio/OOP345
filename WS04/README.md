# Containers
In this workshop, you code a container class that holds notifications and a class that holds separate messages

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- design and code a composition of objects
- read records from a file into a string object
- parse a string object into components based on simple rules

## Specifications
This workshop retrieves messages from a data file and collects them in a notification. Each record in the data file contains a single message and ends with the same delimiting character.

The test data file `tweets.dat` contains the following and should be passed into your program on the command line:

```
jim Workshop 5 is cool
harry @jim working on workshop 5 now
chris
dave what the ^#$%!
john @harry I'm done
```

The first message consists of a user name followed by a tweet. The second message consists of a user name, a reply name prefaced by an @, and followed by a tweet. Your solution ignores incomplete messages, such as the third message here.

Your complete solution to this workshop consists of two modules:
- `Notifications` - the module that holds and manages messages
- `Message` - the module that manages the retrieval and display of a single message

The classes for this workshop are defined in the `w4` namespace.

## Notifications module

A `Notifications` object manages access to a set of up to 10 `Message` objects. The Notifications object collects copies of the `Message` objects, owns those copies and destroys them once they are no longer needed.

Your design of the `Notifications` class includes the following member functions:
- default constructor that sets the current instance in an empty state
- copy constructor
- copy assignment operator
- move constructor
- move assignment operator
- destructor
- `void operator+=(const Message& msg)` — adds msg to the set
- `void display(std::ostream& os) const` — inserts the Message objects to the os output stream

## Message module

A `Message` object holds nothing or a single message that has been successfully retrieved from an std::ifstream object. An object that holds nothing is in a safe empty state.

Your design of the `Message` class includes the following member functions:

- `Message(std::ifstream& in, char c)` — constructor retrieves a record from the in file object, parses the record (as described above) and stores its components in the Message object. `c` is the character that delimits each record
- `bool empty() const` — returns true if the object is in a safe empty state
- `void display(std::ostream&) const` — displays the `Message` objects within the container

## main module

```cpp
// Workshop 4 - Containers
// w4.cpp
// Author: Dr. Elliott Coleshill
// Date: 2018-08-22

#include <iostream>
#include "Message.h"
#include "Notifications.h"

const char REC_DELIMITER = '\n';

w4::Notifications collect(std::ifstream& in, char recDelim)
{
    w4::Notifications notifications;

    do
    {
        w4::Message message(in, recDelim);
        if (!message.empty())
            notifications += std::move(message);
    }
    while(in);

    return notifications;
}

int main(int argc, char* argv[])
{
    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << ' ';
    std::cout << std::endl;

    if (argc == 1)
    {
        std::cerr << argv[0] << ": missing file operand\n";
        return 1;
    }
    else if (argc != 2)
    {
        std::cerr << argv[0] << ": too many arguments\n";
        return 2;
    }
    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << argv[0] << "\n: Failed to open " << argv[1] << "\n";
        return 3;
    }

    std::cout << "\nNotifications\n=============\n\n";
    w4::Notifications notifications = collect(file, REC_DELIMITER);

    notifications.display(std::cout);

    return 0;
}
```

## Output

```
Command Line: w4 tweets.dat

Notifications
=============

Message
 User  : jim
 Tweet : Workshop 5 is cool

Message
 User  : harry
 Reply : jim
 Tweet : working on workshop 5 now

Message
 User  : dave
 Tweet : what the ^#$%!

Message
 User  : john
 Reply : harry
 Tweet : I'm done
```
