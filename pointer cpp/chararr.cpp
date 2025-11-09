#include <iostream>
#include <string>
using namespace std;

int main() {
    char name[6] = {'s','a','r','t','h'};
    char *ptr = name;
    cout << name << endl;
    cout << ptr  << endl;

    //To print the address;

    cout << (void *) name << endl;
    cout << (void *) ptr;

    // cout << *ptr << endl;
    
    // char an = 'a';
    // ptr = &an;
    // cout << ptr << endl;

}