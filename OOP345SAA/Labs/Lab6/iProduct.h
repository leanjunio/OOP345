 #ifndef _I_PRODUCT_H_
 #define _I_PRODUCT_H_

 #include <iostream>
 #include <fstream>

 namespace w6 {

     class iProduct {
       public:
         virtual double getPrice() const = 0;
         virtual void display(std::ostream&) const = 0;
     };

     std::ostream& operator<<(std::ostream&, const iProduct*);
     iProduct* readProduct(std::ifstream&);

 }
 #endif

