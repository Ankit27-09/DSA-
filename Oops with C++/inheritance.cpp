/* Inheritance :-- The capability of a class to derive property and charactersitic from an another class
PUBLIC:-- it can be accessed by the external code, derived class and within class 
PRIVATE:-- It cannot be accessed by external code, not exccessed by derived class but can be accessed by within class.
PROTECTED:-- It cannot be accessed by external code, but accessed within the class and accessed by the derived class.*/ 

/* Derived Class syntax:---
class Student(child name): (access modifier:-- public, protected, private) Human(parent name) {
}*/
// #include <iostream>
// using namespace std;


// class Human{
//     private:
//     int a;

//     protected:
//     int b;

//     public:
//     int c;
   
//     void display() {
//         a = 10;
//         b = 30;
//         c = 20;
//     }

// };

// int main() {
//     Human A1;
//     A1.c = 10;
//     A1.display();


// }

// Derived Class:---

#include <iostream>
using namespace std;

class Human {
    protected:
    string name;
    int age, weight;
};

class Student: public Human {
    int roll_num, fees;
    public:

    Student(string name, int age, int weight){
      this -> name = name;
      this -> age = age;
      this -> weight = weight;
    };

    void display() {
        cout << "name" << name;
    }
};

int main() {
 Student A("ANkit", 23, 56);
 A.display();

};