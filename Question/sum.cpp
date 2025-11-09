#include <iostream> 
using namespace std;

int sum(int num, int result) {
    if(num == 0) {
        return 0;
    }
    else {
        return sum(num - 1, result + num);
    }
}

int main() {
    int num;
    cin >> num;
    int result = 0;
    int resilt =sum(num, result);
    cout << resilt << endl;
}