#include <iostream>
using namespace std;

class Student {
    public:
    string name;
    int age, rollno;
};

int main() {
    Student *S = new Student;
    (*S).name = "Arijit";
    // We can also write *S. => S->
    cout << S -> name << endl;

}