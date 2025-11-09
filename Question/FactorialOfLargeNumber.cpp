// We know if we find out the factorial of a large number it will integer overflow.
// So we will store the digits of the factorial in an array and print it out.

#include <iostream>
#include <vector>
using namespace std;

vector<int> factorial(int n) {
    vector<int> ans(1, 1); // Initialize with 1 as 0! = 1
    while( n > 1) {
        int carry = 0;
        for(int i = 0; i < ans.size(); i++) {
            int prod = ans[i] * n + carry;
            ans[i] = prod % 10; // Store last digit
            carry = prod / 10; // Remaining digits
        }
        while(carry) {
            ans.push_back(carry % 10);
            carry /= 10;
        }
        n--;
    }
}

int main() {
   
    int n = 100; // Example for 100!
    vector<int> result = factorial(n);
    // The digits are stored in reverse order
    for(int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
    } 
    cout << endl;
    return 0;
}