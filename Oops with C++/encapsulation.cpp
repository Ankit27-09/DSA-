/* Encapsulation:--  Wrapping up of data and information in a single unit,
while controlling access to them.
Abstraction:-- Displaying only essential information and hiding the details. */

#include <iostream>
using namespace std;

class Customer {
    string name;
    int account_num, balance;

    public:
    Customer(string name, int account_num, int balance) {
        this -> name = name;
        this -> account_num = account_num;
        this -> balance = balance;
    }

    void deposit(int amount) {
        if(amount > 0) {
            balance += amount;
        }
        else {
            cout << "Invalid Amount " << endl;
        }
    }

    void display() {
        cout << name <<" " << account_num << " " << balance << " " << endl;
    };
};

int main() {
    Customer A1("ROhit", 100, 200);
    A1.deposit(-10);
    A1.display();

}