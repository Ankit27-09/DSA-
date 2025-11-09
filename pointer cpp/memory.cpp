#include <iostream>
using namespace std;

int main() {
    // Variable ke liye heap memory allocate karo

    int *ptr = new int;
    *ptr = 10;
    cout << *ptr;

    float *ptr2 = new float;
    *ptr2 = 3.6;
    cout << *ptr2;

    int n;
    cin >> n;

    int *p = new int[n];

    delete ptr;
}