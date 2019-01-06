Attached Files
- [BadPrices.dat](./Files/BadPrices.dat) (45 B)
- [Descriptions.dat](./Files/Descriptions.dat) (72 B)
- [Element.h](./Files/Element.h) (2.099 KB)
- [List.h](./Files/List.h) (1.238 KB)
- [Prices.dat](./Files/Prices.dat) (44 B)
- [Utilities.cpp](./Files/Utilities.cpp) (604 B)
- [Utilities.h](./Files/Utilities.h) (286 B)
- [w8.cpp](./Files/w8.cpp) (3.256 KB)

# Smart Pointers
In this workshop, you merge two lists and use a smart pointer to ensure that memory is deallocated in the event of an exception.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- create a program component of quadratic complexity
- use a smart pointer to move an object

## Specifications
This workshop consists of the following code files:

- `Element.h` — partially implemented
- `List.h` — partially implemented
- `Utilities.h` — already provided, __do not modify!__
- `Utilities.cpp` — partially implemented
- `w8.cpp` — already provided, __do not modify!__
and the following input files:

- `Prices.dat`
- `BadPrices.dat`
- `Descriptions.dat`
Do not change the code already provided — add the missing parts!

### `Element` module
The `Description` structure holds a product code and a user-friendly description.

The `Price `structure holds a product code and the current price.

The `Product` structure holds a user-friendly description and the price of a product.

### `List` Module
The `List` module defines a class that retrieves a list of records stored in a text file, holds the elements in an STL vector, provides access to them by index and displays them to an output stream.

#### Task 1: validate
Update the `Product` structure, by adding a function named `validate()`. This function throws an exception if the stored price is a negative value. The message thrown is `*** Negative prices are invalid ***`. The exception is caught by the `main(...)` function.

Implement this function inline.

#### Task 2: Add to List
Extend the template class `List`, by providing two member overloads of the operator `+=`. The first overload should receive a parameter of type T* while the second overload should receive as parameter a smart pointer (unique) to an object of type `T`.

Both overloads should add the parameter to the vector.

#### Task 3: Merging the Data Sets
Complete the coding of the `mergeRaw(...)` and `mergeSmart(...)` functions from the module `Utilities`.

These functions return the user-friendly price list. Each element in that list is of `Product` type.

Your function compares elements in the two received lists for common product codes and builds the user-friendly list from the matching pairs. Each function allocates **dynamic memory** for each user-friendly element, validates it (by calling the function `validate()`, and adds that element to the new list by passing

- the object’s raw pointer to the list’s `+=` operator.
- a unique smart pointer to the list’s `+=` operator
For the raw pointer version, delete the object after it has been added to the list.

## `main` Module
The tester module has been attached to this post.

Notice that the raw pointer version of the merge function has a memory leak if an exception is thrown during validation. The smart pointer version doesn’t have the leak.

## Sample Output
The output from your completed main program for the file contents listed above should read like:

```
Command Line: ws Descriptions.dat BadPrices.dat Prices.dat

 Code Description
 4662    tomatoes
 4039   cucumbers
 4056     brocoli
 4067      lemons
 4068     oranges

********************************************
* Good Prices
********************************************
 Code   Price
 4067    0.99
 4068    0.67
 4039    1.99
 4056    2.49

********************************************
* Bad Prices
********************************************
 Code   Price
 4067    0.99
 4068    0.67
 4039    1.99
 4056   -2.49

********************************************
* Merging bad prices using Raw Pointers
********************************************
     C [1]
    CC [2] from [1]
    ~D [1]
     C [3]
    ~D [2]
ERROR: *** Negative prices are invalid ***
NOTE: An exception occured while creating the list of products!
      You should notice that not all objects are deleted.

********************************************
* Merging bad prices using Smart Pointers
********************************************
     C [4]
    CC [5] from [4]
    ~D [4]
     C [6]
    ~D [6]
    ~D [5]
ERROR: *** Negative prices are invalid ***
NOTE: An exception occured while creating the list of products!
      You should notice that ALL objects are deleted.

********************************************
* Merging good prices using Raw Pointers
********************************************
 Description   Price
   cucumbers    1.99
     brocoli    2.49
      lemons    0.99
     oranges    0.67

********************************************
* Merging good prices using Smart Pointers
********************************************
 Description   Price
   cucumbers    1.99
     brocoli    2.49
      lemons    0.99
     oranges    0.67
```