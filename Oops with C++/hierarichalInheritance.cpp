#include <iostream>
using namespace std;

class Human {

  protected:
  string name;
  int age;

  public:
  Human() {

  };
  Human(string name, int age) {
    this -> name = name;
    this -> age = age;
  }

  void display() {
    cout << name << " " << age << endl;
};
};

class Student: public Human {
    string roll_num, fees;
    
    public:
    Student(string name, int age, int roll_num, int fees):Human(name, age){

    }
};

class Teacher: public Human {
    int salary;

    public:
    Teacher( string name, int salary, int age) {
      this -> name = name;
      this -> salary = salary;
      this -> age = age; 
    };

    void display() {
      cout << "name " << name << " age " << age << " salary " << salary << endl;
    }
};


int main() {
   Student A1("Rohit", 12, 10, 90);
   A1.display();
  
   Teacher A2("Naman", 1200, 10);
   A2.display();
};