#include<bits/stdc++.h>
using namespace std;

#ifndef Mystring
#define Mystring

class mystring
{
private:
    char *str;
public:
    mystring(); //No-args constructor
    mystring(const char *s); //Overloaded constructor
    mystring(const mystring &source); //Copy
    ~mystring(); //destructor
    void display() const;
    int get_length() const; //getters
    char *get_str() const;
};

#endif