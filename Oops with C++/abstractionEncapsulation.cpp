// Static Data Member

/* They are attribute of classes or class member
It  is declared using static keyword.
Only one copy of that member is created for the entire class and is shared by all the object.
It is initliazed before any object of this class is created.

*/

/*
Static Member Function 
*/

#include <iostream>
using namespace std;

class Customer {

     string name;
     int account_number, balance;
     static int total_customer;
     static int total_balance;
    
    public:
    Customer(string name, int account_number, int balance) {
        this -> name = name;
        this -> account_number = account_number;
        this -> balance = balance;
        total_customer++;
        total_balance = total_balance + balance;
    };

    public:  
    static void access_static() {
       cout <<"TOTAL NUMBER OF CUSTOMER " <<  total_customer << endl;
       cout << "TOTAL BALANCE IS: "<< total_balance << endl;
    };

    void deposit(int amount) {
        if(amount > 0) {
            balance += amount;
            total_balance+= amount;
        }
    };

    void withdraw(int amount) {
        if(amount <= balance && amount > 0) {
            balance -= amount;
            total_balance -= amount;
        }
    }


    void display() {
        cout << name <<" " << account_number << " " << balance << " " << total_customer  << endl;
    };
};
 
 int Customer:: total_customer = 0;
 int Customer:: total_balance = 0;

int main() {
   Customer A1("Ankit", 123, 99);
   Customer A2("Aman", 123, 99);
   Customer A3("Abdul", 123, 99);

   A1.display();
   A2.display();

   A2.withdraw(23);


   Customer:: access_static();
}