#include <bits/stdc++.h>
using namespace std;


/*
# Procedural Programming (PP)
- Follows a top-down approach
- Easy to write small programs
- Difficult to:
    • Understand
    • Maintain
    • Debug
    • Extend
- Code reusability is low
- Hard to manage large and complex applications
- Focuses on functions
- easy to break 

# Object-Oriented Programming (OOP)
- Follows a bottom-up approach
- Helps developers model real-world entities 
- Ideal for large applications and unknown data structures
- instead of thinking about name roll no. etc for student we can think just student
- Easy to:
    • Maintain
    • Debug
    • Extend
- Promotes code reuse through:
    • Inheritance
        • Can create new classes in term of existing
        • Reusability
        • Ex from  main account inheriting for classes like Saving or Current etc.
        • 
    • Polymorphism
        • 
    • Abstraction
        • 
    • Encapsulation
        • 
- Focuses on objects and classes
    • Class = Blueprint (design)
        • User defined data-type
        • Has attributes = Data
        • Has methods = Function
        • Can hide bot attr,methods
    • Object = Instance of class (design comes true)
        • Created from a class 
            - like if int score we declare score variable
            - if we have Account ex:- class Account Jeetu;
            Jeetu is a variable of Account data type (for understanding)
            Jeetu is a object of Account claa (Actually)
        • Object can use methods of its class
            - Ex vector is class any object from itcan use sort etc through .(dot) operator
        
*/

// Syntax

// This is how we create class
class Player
{
    //This are attributes(Data)
    string name;
    int health;
    int xp;
    //Methods
    void show_xp(){
        //wap to show xp
    }
    void hello();//will declare it explicitively
};

Player Jeetu; // Jeetu is object of Player class

Player *Hero = new Player() ; // pointer to the class Create dynamically allocated memory


/*

    Jeetu.name="Jeetu";
    Jeetu.health=1000;//(.) dot operator used for accesing attr and object for pointers
    Jeetu.xp=1000;

    • For pointers we have 2 methods , 1st derefrencing & then . or using this
    
    (*Hero).name="Hero";//derefrencing and using .
    Hero->health=100;//(->) This operator used for accesing attr and object for pointers
    Hero->xp=100; 
    
    ∴ Jeetu >> Hero  Hence proved

    // Method calling
    Jeetu.show_xp();
    Hero->show_xp();

delete Hero; // Delete dynammically allocated objeect pointer

For complete refrence see player.cpp
*/

// Obejcts can be Used as any other variable like we can create vector of our player object

// Ex

vector <Player> players {Jeetu};

//players.pushback(*hero) to add Hero dunamically
//player[index].method or attr to access method or attr

/*
# Class Member Access Modifier

- Public
• Accessible everywhere

- Private
• Accessible only by members or friends of the class

- Protected
• Similar to Private but also aaccessible to subclass(derived class)

*/

//syntax

class Account
{
private://private members
    
public://public members
   
protected://protected members  

};

//If we try to access unaccesible (Outside its accessible domain) we get compiler error

/*
# Implementing Members Method

- Implicitly inline
• Above all are implicitive inline example

- Outside class declaration
• Can be declasred outside the class 
• Syntax:- return type Class-name::method_name

- Seperate specification from implemantation
• .h file for class declaration
• .cpp file for class implementation
• Account_class folder for details
*/

//outside declaration example

void Player::hello(){
    //method to say hello
}

/*
# Constructur

- Special member method invoked during object creation
- Used for intialization
- Same name as the class
- No return type is specified
- Can be overloaded 
- Default constructor is no arg constructor used when no constructor is written
- If we create any constructor default will be no longer available

*/

/*
# Destructur

- Special member method invoked during object destruction 
- Used to release memory and other resources
- Same name as the class with a tilde (~)
- No return type is specified
- only 1 destructor is allowed cant be overloaded

*/

//Syntax

class pokemon
{
private:
    string name;
    int health;
    int xp;
public:
    pokemon(string name);//1 arg constructor
    pokemon(string s,int hp){//overloading contructor
        name = s;// this is assignment not intialization
        health = hp;
    }
    pokemon() : name  {"none"}, health{0} {//better way its intialization here

    }
    //Delegating Constructor
    //Code for one and can be called in another in the intialization list
    //avoids duplicating ex:-
    pokemon(int hp) 
        : pokemon{"none",hp}
    {

    }
    ~pokemon();//destructor
    
};


/*
# Copy Constructor

- Why Copy Constructor is Needed:
    • When passing objects by value to functions
    • When returning objects from functions by value
    • When constructing a new object as a copy of an existing object

- If we don't define a copy constructor, C++ provides a default one
- Default copy constructor performs a shallow copy
    → Copies the values of each data member (bitwise copy)
    → If the object has a pointer, only the pointer is copied (not the data it points to)

- Shallow Copy Issues:
    • Two objects share the same memory
    • When one is destroyed, it may delete memory still used by the other → leads to double deletion

- Deep Copy:
    • Allocates separate memory
    • Copies the actual data, not just the pointer

- Use a custom copy constructor for classes with raw pointers
- Prefer smart pointers to avoid manual memory management

- Syntax:
    class_name(const class_name &source); 
*/

// Shallow & Deep ex:-

class shallow {
private:
    int *data;
public:
    shallow(int d);                    // Constructor
    shallow(const shallow &source);   // Copy Constructor
    ~shallow();                        // Destructor
};

shallow::shallow(int d) {
    data = new int;
    *data = d;
}

shallow::shallow(const shallow &source)
    : data(source.data) {
    // ❌ This is a shallow copy
}

shallow::~shallow() {
    delete data;
}

// ------------------------------------------------

class deep {
private:
    int *data;
public:
    deep(int d);                      // Constructor
    deep(const deep &source);        // Deep Copy Constructor
    ~deep();                         // Destructor
};

deep::deep(int d) {
    data = new int;
    *data = d;
}

deep::deep(const deep &source) {
    data = new int;
    *data = *source.data;  // ✅ Deep copy
}

deep::~deep() {
    delete data;
}

/*
# Move Constructor

- Introduced in C++11
- Optimizes temporary object usage (especially return-by-value)
- Transfers ownership of resources from source to the new object
- Avoids deep copying for temporary objects
- Optional to use but recommended when you have a raw pointer 

- Syntax:
    class_name(class_name &&source); (&& = R-value refrences)

- Used When:
    • Moving temporary objects
    • Return-by-value where RVO (Return Value Optimization) doesn't apply
    • Working with resources (like dynamic memory, files, etc.)

- Inside Move Constructor:
    • Steal the resource (e.g., pointer)
    • Nullify the source's pointer to avoid double deletion

- Tip:
    • Mark the source object as `&&` (rvalue reference)
*/

class move {
private:
    int *data;
public:
    move(int d);
    move(const move &source);      // Copy Constructor
    move(move &&source);           // Move Constructor
    ~move();
};

move::move(int d) {
    data = new int;
    *data = d;
    cout << "Constructor called\n";
}

move::move(const move &source)
    : data(new int(*source.data)) {
    cout << "Copy Constructor called\n";
}

move::move(move &&source)
    : data(source.data) {
    source.data = nullptr;  // prevent double delete
    cout << "Move Constructor called\n";
}

move::~move() {
    delete data;
    cout << "Destructor called\n";
}

/*
# This pointer
- Contains address of the object - its pointer to the object
- Can only use in class scope 
- All member access is done via this pointer 
- Usecase:-
    • To access data mem and methods
    • To check if both obj are same 
    • Can be derefrenced(*this)

balance = bal (this->balance = bal actual code)

*/

/*

# const with Classes

Why use const in classes?
- To protect object data from being modified accidentally.
- Helps make code more readable and safer.

----------------------------------

1. const Member Function
- Use 'const' after the function definition.
- It promises not to modify any member variables.

Syntax:
    return_type function_name() const;

Example:
    class Account {
        double balance;

    public:
        double get_balance() const {
            return balance;
        }

        void set_balance(double b) {
            balance = b;
        }
    };

----------------------------------

2. const Objects
- If an object is declared as const, it cannot call non-const functions.

Example:
    const Account acc;
    acc.get_balance(); // ✅ allowed
    acc.set_balance(500); // ❌ error

----------------------------------

3. const Function Parameters
- Prevents the parameter from being changed inside the function.

Example:
    void print_account(const Account &acc) {
        acc.get_balance(); // ✅
        // acc.set_balance(100); ❌
    }

----------------------------------

4. const Return Values
- Prevents the returned value from being modified.

Example:
    class Account {
        string name;
    public:
        const string& get_name() const {
            return name;
        }
    };

----------------------------------

Summary:
- Use const to write safer and cleaner code.
- const member function → doesn’t modify data.
- const object → can’t call non-const functions.
- const parameter → can’t change the argument.
- const return → avoids accidental modifications.

*/

/*
# struct vs class

- Both struct and class are used to define user-defined types.

Similarities:
- Can have variables and functions
- Can use constructors and destructors
- Support inheritance and polymorphism

Main difference:
- struct: members are public by default
- class: members are private by default

Example:

    struct Person {
        string name;   // public
        int age;       // public
    };

    class Player {
        string name;   // private
        int score;     // private

    public:
        void display(); // public
    };

Usage:
- Use struct for simple data structures (like plain objects)
- Use class when data hiding, encapsulation, and abstraction are needed
*/

/*
#friend of class

- A friend function or friend class can access private and protected members of the class.

Why use:
- To allow certain external functions or classes to access private members
- Useful for operator overloading and related utility functions

- Syntax:

    class MyClass {
        private:
            int data;
        public:
            friend void showData(MyClass &obj);  // function is a friend
            //class can also be friend
    };

    void showData(MyClass &obj) {
        cout << obj.data;  // allowed because it's a friend
    }

- Imp points:
    • friendship is one-way (not mutual)
    • not inherited by derived classes
    • does not break encapsulation if used wisely
*/
