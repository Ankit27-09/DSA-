// Binary Exponentiation (also called Exponentiation by Squaring) is a fast algorithm to compute:
// ab(a raised to the power b)

// in O(log b) time instead of O(b).

// if b is even:
// ab = (a^(b/2))^2
// if b is odd:
// ab = a * (a^(b/2))^2

//  Recursive implementation of binary exponentiation
#include <iostream>
using namespace std;

// Function to perform binary exponentiation
int binaryExponentiation(int a, int b) {
    // Base case: a^0 = 1
    if (b == 0) {
        return 1;
    }

    // Recursive case
    int halfPower = binaryExponentiation(a, b / 2);

    // If b is even
    if (b % 2 == 0) {
        return halfPower * halfPower;
    } else { // If b is odd
        return a * halfPower * halfPower;
    }
}

int main() {
    int a, b;
    cout << "Enter base (a) and exponent (b): ";
    cin >> a >> b;

    int result = binaryExponentiation(a, b);
    cout << a << "^" << b << " = " << result << endl;

    return 0;
}