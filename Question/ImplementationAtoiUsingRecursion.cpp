// Implementation of String to Integer (atoi) using Recursion
#include <iostream>
#include <string>
using namespace std;

/*
atoiRec function:
-----------------
This function converts a numeric string into an integer using recursion.
- str  -> input numeric string (without '+' or '-')
- n    -> length of the string

Logic:
1. Base case: when string has only 1 character (n == 1), return its numeric value.
2. Recursive case: convert the first (n-1) digits, then multiply by 10 and add the last digit.
   Example: "1234"
     -> convert("123") * 10 + 4
     -> convert("12") * 10 + 3
     -> convert("1") * 10 + 2
     -> returns final number.
*/
int atoiRec(string str, int n) {
    // Base case: single character
    if (n == 1) {
        return str[0] - '0'; // Convert char to integer
    }

    // Recursive case:
    // Get smaller result for first (n-1) digits
    int smallerOutput = atoiRec(str, n - 1);

    // Get last digit
    int lastDigit = str[n - 1] - '0';

    // Combine: shift smallerOutput by one digit (multiply by 10) and add lastDigit
    return smallerOutput * 10 + lastDigit;
}

/*
myAtoi function:
----------------
This function handles signs (+ or -) and calls atoiRec to convert string into integer.

Steps:
1. Check if string is empty -> return 0.
2. Check if first char is '+' or '-' -> update sign and remove it from string.
3. Pass the remaining numeric string to atoiRec.
4. Apply sign to result.
*/
int myAtoi(string str) {
    // Handle empty string
    if (str.empty()) {
        return 0;
    }

    bool isNegative = false;

    // Handle sign
    if (str[0] == '-') {
        isNegative = true;
        str = str.substr(1); // Remove '-' for processing
    } else if (str[0] == '+') {
        str = str.substr(1); // Remove '+' for processing
    }

    // If string becomes empty after removing sign, return 0
    if (str.empty()) {
        return 0;
    }

    // Convert numeric string to integer using recursion
    int result = atoiRec(str, str.length());

    // Apply sign
    return isNegative ? -result : result;
}

// Driver code
int main() {
    string input1 = "1234";
    string input2 = "-5678";
    string input3 = "+910";

    cout << "Input: " << input1 << " -> Output: " << myAtoi(input1) << endl;
    cout << "Input: " << input2 << " -> Output: " << myAtoi(input2) << endl;
    cout << "Input: " << input3 << " -> Output: " << myAtoi(input3) << endl;

    return 0;
}
