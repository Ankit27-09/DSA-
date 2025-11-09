#include <iostream>
using namespace std;

int main() {
    int a = 10;
    cout << &a << endl; // The address will be in Hexadecimal format. This we will get to know by 0x at the beginning[0x29c33ffc3c].
    
    int *ptr;  // Declare the pointer
    ptr = &a;  // Assign the address of 'a' to the pointer
    cout << ptr << endl;  // Output the pointer value (address of 'a')
    
    int b = 20;
    ptr = &b;  // Now assign the address of 'b' to the pointer
    cout << *ptr << endl;  // Output the pointer value (address of 'b')

    return 0;
}
