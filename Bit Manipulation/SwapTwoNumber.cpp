// Swap two Numbers without the third variable

// How?
// take a = a ^ b
// take b = a ^ b // here b = a we take the value of a from above 
// take a = a ^ b // here a = b we take the value of b from above

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    a = a ^ b; // step 1
    b = a ^ b; // step 2
    a = a ^ b; // step 3
}