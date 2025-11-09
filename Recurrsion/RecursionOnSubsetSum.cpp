

#include <iostream>
using namespace std;

void printArr(int arr[], int index, int n, int sum) {
    if (index == n) {
        cout << "Subset sum: " << sum << endl;
        return;
    }
    
    // Include the current element
    printArr(arr, index + 1, n, sum + arr[index]);
    
    // Exclude the current element
    printArr(arr, index + 1, n, sum);
}

int main() {
    int arr[] = {1,2,3,4};
    printArr(arr, 0, 4, 0);
}