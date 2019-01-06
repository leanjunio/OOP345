# STL Containers
In this workshop, you store a set of polymorphic objects in an STL container.

## Learning Outcomes
Upon successful completion of this workshop, you will have demonstrated the abilities to
- store and manage polymorphic objects using an STL vector
- store a set of uniform rates for all instances of a class using a class array
- report and handle an exception

## Specifications
This workshop consists of the following:
- `w6` — the main program receives the name of the file that holds information about the products sold to a customer; only `*.cpp` file
- `iProduct` hierachy — each object describes a single product sold to the customer; only `*.h` file
- `Product` — concrete class; inherits from iProduct; `*.h` and `*.cpp` file
- `TaxableProduct` — concrete class; inherits from Product; `*.h` and `*.cpp` file
- `ProdUtil` — module that contains helper functions; `*.h` and `*.cpp` file

The main program receives a user-specified file (`sales.dat`) via command line arguments. The records hold price information about products, some of which are taxable. Taxable and non-taxable products belong to the same hierarchy; the taxable product class derives from the simpler product class.

## File Records
Each record in the file consists of two or three fields: a product number field, a product cost field and an optional taxable code field. The cost field contains the price before any tax.

A sample of the input file is shown below:
```
10012 34.56
10023 45.67 H
10234 12.32 P
10056 67.54
20202 11.22 C
10032  2.34 H
10029 54.12
04301 84.00 H
10044 17.89 P
10035 96.30
10001 44.12 M
00004  8.01
```

where,
- `H` identifies a taxable product at the HST rate
- `P` identifies a taxable product at the PST rate
- `C` and `M` are invalid

A non-taxable record terminates with a newline character immediately following the price field. A record with a taxable code other than `H` and `P` is an invalid record. Invalid records should generate an exception when processing.

## `iProduct` Hierarchy
The `iProduct` hierarchy holds information about the different products purchased by a customer. The interface to this hierarchy is defined in the `iProduct.h` file provided.

- `double getPrice() const` — a query that returns the price chargeable to the customer.
- `void display(std::ostream& os) const` — a query that receives a reference to the output stream and inserts the product information in the form of a single line into the output stream.
  - The product code and price should be printed on fields of width 16 characters.
- The overloaded insertion operator (`<<`) receives a reference to the output stream and displays the product information in the form of a single line on the output stream.
- The `readProduct(...)` function receives a reference to the input file stream, reads the next record from the stream, allocates memory for the corresponding `iProduct` object, copies the record information into that object and returns its address to the caller.
  - If the tax code is not valid (i.e., `H` or `P`) an exception of type `std::string` should be thrown, with the message `Unrecognizable Tax Code!`.
  - If the record read from the file is empty (empty line), this funtion returns `nullptr` as a signal that the end of file has been reached.
  - **this function should not print anything on the screen!**

## Implementations
Complete the definition of the polymorphic `iProduct` object by implementing two distinct classes:

- `Product` — holds information about a product that consists of its product number and its cost
- `TaxableProduct` — derives from `Product` and holds additional information about the product’s taxable status
The same tax rates apply to all TaxableProduct objects. Use a **class array** (an array of class variables; i.e., static member) to store the tax rates for HST and PST tax codes (13% and 8%).

Complete the implementation of the functions from the module ProdUtil.

Do not modify the files `ProdUtil.h` and `iProduct.h` already provided.

```cpp
// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>

namespace w6
{
    class iProduct
    {
    public:
        virtual double getPrice() const = 0;
        virtual void display(std::ostream&) const = 0;
    };
}
#endif
```
```cpp
// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include <iostream>
#include <fstream>
#include "iProduct.h"

namespace w6
{
    std::ostream& operator<<(std::ostream&, const iProduct&);
    iProduct* readProduct(std::ifstream&);
}
#endif
```

## `main` Module
Complete main program provided by adding a vector of `iProduct*` and populating the STL container with the **valid** data from the `sales.dat` input file. If an exception is thrown while processing a record (invalid tax rate has been found), the main program prints the exception message and moves to the next record.

Do not modify the `main` module in any other places than those marked with `TODO`. Do not change the code already provided, only add the missing parts!

```cpp
// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

    std::cout << "Command Line: ";
    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << ' ';
    }
    std::cout << std::endl;
    if (argc != 2) {
        std::cerr << "\n***Incorrect number of arguments***\n";
        return 1;
    }
    std::ifstream productList(argv[1]);
    if (!productList) {
        std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
        return 2;
    }
    std::cout << std::fixed << std::setprecision(2);

    // TODO: Define a variable ot type vector named "products"


    std::cout << "====================================\n";
    std::cout << "Reading data from the file\n";
    std::cout << "====================================\n";
    {
        // TODO: Read from the file one record at a time and create a product.
        // - Print a message before starting processing a product.
        // - Add the product to the vector "products", created above.
        // - Handle any thrown exceptions and print the message.

    }
    std::cout << "====================================\n";

    std::cout << std::endl;
    std::cout << "====================================\n";
    std::cout << "Printing the content of the vector\n";
    std::cout << "====================================\n";

    double total = 0.0;
    std::cout << " Product No Taxable\n";
    std::cout << "------------------------------------\n";
    for (auto i = 0u; i < products.size(); i++) {
        total += products[i]->getPrice();
        std::cout << *products[i];
    }
    std::cout << "------------------------------------\n";
    std::cout << std::setw(22) <<"Total: ";
    std::cout << std::setw(10) << total << std::endl;
    std::cout << "====================================\n";

    return 0;
}
```

## Sample Output
The output from your completed main program for the file contents listed above should read like:

```
Command Line: ws sales.dat
====================================
Reading data from the file
====================================
Processing record 1: done!
Processing record 2: done!
Processing record 3: done!
Processing record 4: done!
Processing record 5: Unrecognizable Tax Code!
Processing record 6: done!
Processing record 7: done!
Processing record 8: done!
Processing record 9: done!
Processing record 10: done!
Processing record 11: Unrecognizable Tax Code!
Processing record 12: done!
Processing record 13: no such record! Reached the end of the file!
====================================

====================================
Printing the content of the vector
====================================
      Product No         Taxable
------------------------------------
           10012           34.56
           10023           45.67 HST
           10234           12.32 PST
           10056           67.54
           10032            2.34 HST
           10029           54.12
           04301           84.00 HST
           10044           17.89 PST
           10035           96.30
           00004            8.01
------------------------------------
               Total:     442.33
====================================
```