#include "Account.h"
//declare all methods here
void Account::set_name(string s) {
    holder_name = s;
}

void Account::set_balance(double bal) {
    balance = bal;
}

double Account::get_balance() {
    cout<<holder_name<<"'s Account"<<endl;
    return balance;
}
