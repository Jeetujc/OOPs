#include <bits/stdc++.h>
using namespace std;

#ifndef Mystring
#define Mystring

class mystring
{
private:
    char *str;

public:
    mystring();                       // No-args constructor
    mystring(const char *s);          // Overloaded constructor
    mystring(const mystring &source); // Copy
    ~mystring();                      // destructor
    void display() const;
    int get_length() const; // getters
    char *get_str() const;
    mystring &operator=(const mystring &rhs); // Copy assignment Operator
    mystring &operator=(mystring &&rhs);      // Move assignmet
    mystring operator~() const;               // Example of unary (operator tolower)
    bool operator!() const;                   // Check if string is empty or not
    // Binary operators
    mystring operator+(const mystring &rhs) const; // Concatenate
    bool operator==(const mystring &rhs) const;    // Compare

    friend mystring operator-(const mystring &obj); // global function delaration to change case of letter

    friend istream& operator>>(std::istream& is, mystring& obj);
    friend ostream& operator<<(std::ostream& os, const mystring& obj);

};

#endif