#include<bits/stdc++.h>
using namespace std;

//if headers files includes more than 1 time it gives error to tackle that
//we use ifndef(if not define) and define (Known as Include guard)
#ifndef Account_H //if not defined define it using below line
#define Account_H//defines
//can use #pragma once if compiler support it instead of everything else
class Account
{
private:
    string holder_name;
    double balance;
public:
    void set_name(string s);
    void set_balance(double bal);
    double get_balance();

};

#endif//if definned end