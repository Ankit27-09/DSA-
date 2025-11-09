#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1,2,3,4,5,};
    int *ptr = arr;
    //Printing the address of elements of array
    cout << arr << endl; // arr stores the first index adddress.
    cout << &arr[0] << endl;
    cout << &arr[1] << endl;
    cout << (arr+0) << endl;


    //Printing the second index element
     cout << (arr +2);

     //For loop and to get the value of array with pointer..
      for (int i = 0; i < 5; i++) {
         cout << *(ptr + i);
      }


}