#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int *ptr = &num;
    int **ptr2 = &ptr;
    cout << num << " " << ptr << ptr2;
}