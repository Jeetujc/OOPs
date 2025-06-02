#include <bits/stdc++.h>
#include "Account.h" //include header file

int main(){
    Account Jeetu_acc;
    Jeetu_acc.set_name("Jeetu");
    Jeetu_acc.set_balance(50000.75);
    
    cout << "Balance: " << Jeetu_acc.get_balance() << endl;
}

//note while compiling also compile ur class_name.cpp file along with main.cpp
//compiling command is ex:- g++ main.cpp Account.cpp -o main