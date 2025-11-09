#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num = 10;
    int count = 0;

    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            count++;
            if (num / i != i) { // avoid double-counting when i*i == num
                count++;
            }
        }
    }

    if (count == 2) {
        cout << "Prime" << endl;
    } else {
        cout << "Not Prime" << endl;
    }

    return 0;
}
