// We are converting the decimal number to binary number
//Simple Approach
//

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int rem, ans = 0, mul = 1;

    while(num > 0) {
        // Remainder part
        rem = num % 2;

        ans = ans + rem * mul;

        mul = mul * 10;
        // Update the number by dividing it by 2
        num = num / 2;
    }

    cout << ans;
    return 0;
}