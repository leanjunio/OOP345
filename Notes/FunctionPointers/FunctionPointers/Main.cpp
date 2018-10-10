/*

Function Pointers

What is a function pointer?
A pointer that holds the memory address of a function type

How to define a function pointer?
return-type (*identifier)(parameters) = fn;

fn: the initial address of the function
*/

// Names a pointer that holds the address of a region of type T
template <typename T>
T* ptrToObject;

// Names a pointer that holds the address of type T (*)(T&)
template <typename T>
T(*ptrToFunction)(T&);

// Names a function that receives a reference of type T and returns the address of T
template <typename T>
T* ptrTofunc(T&);


// How to define the ptrToFunction?
template <typename T>
T(*ptrToFunction)(T&) = &fn;

// NOTE: &fn is optional (fn will work as well due to implicit conversions)

// To change the function that the pointer is pointing to...
ptrToFunction = gn;