#include <iostream>
using namespace std;

class Human { 
    protected:
    string name;
    int age;

    public:
    Human(string name, int age){
        this -> name = name;
        this -> age = age;
    }

    void work(){
        cout << "I am working \n"; 
    }
};

class Student: public Human{
   int roll_num, fees;

   public:
   Student(string name, int age, int roll_num, int fees) :Human(name,age){
    
     this -> roll_num = roll_num;
     this -> fees = fees;
   }
   void display() {
        cout << name <<" " << age <<" "<<  roll_num << fees;
   }

  
};

int main() {
  Student A1("Rak", 20, 21, 2122);
  A1.work();
  A1.display();
}