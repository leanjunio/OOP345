 // Workshop 10 - Multi-Threading
 // SecureData.h

 #include <iostream>

 namespace w10 {

     class Cryptor {
       public:
         char operator()(char in, char key) const { return in ^ key; } 
     };
     void converter(char*, char, int, const Cryptor&);

     class SecureData {
         char* text;
		 std::ofstream* ofs;
         int nbytes;
         bool encoded;
         void code(char);
       public:
         SecureData(const char*, char, std::ofstream*);
         SecureData(const SecureData&) = delete;
         SecureData& operator=(const SecureData&) = delete;
         ~SecureData();
         void display(std::ostream&) const;
         void backup(const char*);
         void restore(const char*, char);
     };
     std::ostream& operator<<(std::ostream&, const SecureData&);
 }
