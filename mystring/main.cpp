#include"mystring.h"

int main(){
    mystring a;
    {
        mystring b{"Jeetu"};
        a=b; // Copy Assignment Operator is Called
        b="Hello"; // Move Assignment Operator is Called
        b=~b; //tolower
        cout<<b.get_str()<<" : "<<b.get_length()<<endl;
    }
    a = a+" is OP";
    cout<<a.get_str()<<" : "<<a.get_length()<<endl;
    mystring jeetu;
    cin>>jeetu;
    cout<<jeetu.get_str()<<" : "<<jeetu.get_length()<<endl;
    cout<<jeetu<<endl;
}
