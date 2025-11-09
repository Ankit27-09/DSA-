/*Destructor:- It is an instance member function that is invoked automatically whenever an object is going to be destroyed.
It is the last function that is going to be called before an object is destroyed.
It is not possible to define more than one destructor.
Destructor has the same name as their class name preceded by a tilde (~) symbol. */
// Destructor release memory space occupied by the objects created by the constructor.
// Both constructor and destructor is in public

#include <iostream>
using namespace std;

// class Customer{
//     string name;
//     int *data;

//     public:
//     Customer() {
//         name = "Ankit",
//         data = new int;
//         *data = 10;
//         cout << "Constructor is called \n";
//     }
// // Destructor
//     ~Customer() {
//         delete data;
//        cout << "Destructor is called";
//     }
// };

// int main() {
//    Customer A1;
// }

/* In C++, objects are destroyed in the reverse order of their creation because of the Last In, First Out (LIFO) principle, which is the way memory management works in most block-scoped programming languages, including C++.*/
/* Resource Safety: This guarantees that dependencies between objects are respected. If object A1 depends on A2 and A3, destroying A3 first ensures that resources of A2 and A1 are still available during A2's and A1's destruction.*/
class Customer {
    string name;
    int *data;

    public:
    Customer() {
        name = "4";
        cout << "Constructor is called for " << name << endl;
    }
    Customer(string name) {
        this->name = name;  // Properly initialize the name
        cout << "Constructor is called for " << name << endl;
    }

    ~Customer() {
        cout << "Destructor is called for " << name << endl;
    }
};

int main() {
    Customer A1("1"), A2("2"), A3("3");  // Creating 3 Customer objects
    Customer *A4 = new Customer;
    delete A4;
}
