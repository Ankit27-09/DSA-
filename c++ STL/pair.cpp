// pair <type1, type2> name_of_pair;
// pair <string, int> p1;

// To make the pair we can use make_pair function`
// make_pair("C++", 4);

// cout << p.first << " " << p.second << endl;
// Another method is to use the dot operator

// p.first = "Ankit";
// p.second = 1;
// cout << p.first << " " << p.second << endl;

// pair <string, double> p2;

#include <iostream>

using namespace std;

        

int main() {
    pair<string, int> p;
    // Two method

    // 1. Method is used to make use of make_pair function
    p = make_pair("C++", 4);
    cout << p.first << " " << p.second << endl;

    // 2. Method is used to make use of dot operator
    p.first = "Ankit";
    p.second = 1;
    cout << p.first << " " << p.second << endl;
}