#include <iostream>
using namespace std;

class Engineer {
    public:
    string specialization;

    void work() {
        cout << "I have specialization in " << specialization << endl;
    }
};

class Youtuber{
    public:
    int suscribers;
    
    void contentcreator(){
        cout << " I have a suscriber base of " << suscribers << endl;
    }
};

class CodeTeacher: public Engineer, public Youtuber {
    public:
    string name;

    CodeTeacher(string specialization, int suscribers, string name) {
        this -> specialization = specialization;
        this -> suscribers = suscribers;
        this -> name = name;
    };

    void showcase() {
        cout << " specialization " << specialization << " suscribers " << suscribers << " name " << name << endl;
    }

    };

int main() {
    CodeTeacher A1("DSA", 234, "Ankit");
    A1.showcase();
    A1.work();
}
