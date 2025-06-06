#include <bits/stdc++.h>
#include "mystring.h"
using namespace std;

mystring::mystring()
    : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

mystring::mystring(const char *s)
    : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1]; // Allocate space for the string + '\0'
        strcpy(str, s);                // Copy the input string into str
    }
}

// Copy Constructor
mystring::mystring(const mystring &source)
    : str{nullptr}
{
    str = new char[strlen(source.str) + 1]; // Allocate space for the string + '\0'
    strcpy(str, source.str);
}

// Destructor
mystring::~mystring()
{
    delete[] str; // Release the allocated memory
}

void mystring::display() const
{
    cout << str << endl;
}