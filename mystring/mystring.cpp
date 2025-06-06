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

int mystring::get_length() const
{
    return strlen(str);
}

char *mystring::get_str() const
{
    return str;
}

mystring &mystring::operator=(const mystring &r)
{
    if (this == &r)
        return *this;
    cout << "CA" << endl;
    delete[] str;
    str = new char[strlen(r.str) + 1];
    strcpy(str, r.str);
}

mystring &mystring::operator=(mystring &&r)
{
    if (this == &r)
        return *this;
    cout << "MA" << endl;
    delete[] str;
    str = r.str;
    r.str = nullptr;
    return *this;
}

// operator~: converts to lowercase
mystring mystring::operator~() const {
    mystring temp(*this);
    for (int i = 0; temp.str[i] != '\0'; ++i)
        temp.str[i] = tolower(temp.str[i]);
    return temp;
}

// operator!: returns true if string is empty
bool mystring::operator!() const {
    return str[0] == '\0';
}

// Binary + to concatenate
mystring mystring::operator+(const mystring& rhs) const {
    char* buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    mystring temp(buff);
    delete[] buff;
    return temp;
}

// Binary == to check equality
bool mystring::operator==(const mystring& rhs) const {
    return strcmp(str, rhs.str) == 0;
}

mystring operator-(const mystring& obj) {
    mystring temp(obj);
    for (int i = 0; temp.str[i] != '\0'; ++i) {
        if (islower(temp.str[i]))
            temp.str[i] = toupper(temp.str[i]);
        else if (isupper(temp.str[i]))
            temp.str[i] = tolower(temp.str[i]);
    }
    return temp;
}