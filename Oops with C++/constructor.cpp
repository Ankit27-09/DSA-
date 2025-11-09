#include <iostream>
using namespace std;

// Constructor 
// It is a special function that is invoked automatically at the time of object creation.
// It is used to initialize the value.
// It doesn't have any return value.
// Name of the constructor should be same as class name.

// * Both Constructor and Destructor will be in public section
class Customer {
    public:
    string name;
    int account_num;
    int balance;

    //Default Constructor
    Customer() {
        name = "Unknown";
        account_num = 0;
        balance = 0;
    }

// A parameterized constructor is a constructor that accepts parameters, or arguments, when an object is created. 
    // Customer(string a, int b, int c) {
    //   name = a;
    //   account_num = b;
    //   balance = c;
    // }

// In C++, We can have more than one constructor in a class with same name, as long as each has a different list
// of arguments.This concept is known as Constructor Overloading and is quite similar to function overloading. 
    Customer(string a, int v ) {
      name = a;
      balance = v;
      account_num = 500;
    }

    Customer(string name, int account_num, int balance) {
        this -> name = name;
        this -> account_num = account_num;
        this -> balance = balance;
    }

    // Inline Constructor
    // Constructor in C++ is a special method that is invoked automatically at the time an object of a class is created. 
    //It is used to initialize the data members of new objects generally. 

    /* inline Customer(string a, int b, int c): name(a), account_num(b), balance(c){
    } */

  //  Copy Constructor
  /*Copy constructor takes a reference to an object of the same class as an argument.
  a constructor which creates an object by initializing it with an object of the same class, which has been created previously is known as a copy constructor.  */
    Customer(Customer &B) {
      name = B.name;
      account_num = B.account_num;
      balance = B.balance;
    }
    
    public:
    void display() {
      cout << name << "  " << account_num <<  "  " << balance << endl;
    }
};

int main() {
   Customer C1("Rohit", 123, 1200);
   C1.display();

   Customer C2("Ankit", 1012);
   C2.display();

   Customer C3(C1);
   C3.display();

// Value assignment with assignment operator.
   Customer C4;
   C4 = C3;
   C4.display();
}
