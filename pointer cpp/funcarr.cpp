#include <iostream>
using namespace std;

// Pass by pointer...
// void incr(int *n) {
//     *n = *n + 1 ;

// }
// int main(){
//     int num = 6;
//     int temp = num;

//     incr(&num);

//     cout << num;

// }

void doubble(int *ptr) {
    for(int i = 0; i< 5; i++) {
         2* (*(ptr +i));
    }
}

int main() {
    int arr[5] = {1,2,3,4,5};

    doubble(arr);
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << endl;
    }
}