#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    int rem, ans = 0, mul = 1;

    while(num > 0) {
        // Remainder part
        rem = num % 10;

        ans = ans + rem * mul;

        mul = mul * 2;
        // Update the number by dividing it by 10
        num = num / 10;
    }
    cout << "ans is" << " " << ans;
    return 0;
}