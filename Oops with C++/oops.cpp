#include <iostream>
using namespace std;

// Class is a user defined data type 
// Blue print for creating object
// Object is an entity that has a state and behaviour

class Student {
    private:
    string name;
    int age, roll_number;
    string grade;
    
    //  Function Getter and Setter method
    public:
    void setName(string n) {
        name = n;

    }
    void setAge(int a) {
        age = a;

    }
    void setRoll(int roll_num) {
        roll_number = roll_num;

    }
    void setGrade(string s) {
        grade = s;

    }
    void getName() {
        cout << name;
    }

    int Vage() {
        return age;
    }

};

int main() {
// s1 is the object here 
//    Student s1;
//    s1.name = "Ankit";
//    s1.age = 10;
//    s1.roll_number = 28;
//    s1.grade = "A+";

//    cout << s1.age << " " << endl;

// Calling Function
    Student S1;
    S1.setName("Ankit");
    S1.setAge(20);

    S1.getName();
    int ans = S1.Vage();
    cout << ans << endl;

    Student s2;
    s2.setName("Rohit");
    s2.setAge(10);
    s2.getName();
    
}
