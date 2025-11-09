#include <iostream>
#include <vector>
#include <algorithm> // for the sort function   
#include <numeric> // for the accumulate function
using namespace std;

// 1 Approach having O(n2) complexity

// int main() {
//     int arr[] = {3, 4, -2, 5, 8, 20, -10, 8};
//     int n = sizeof(arr)/ sizeof(arr[0]); // size of the array
    
//     for(int i = 0; i < n - 1; i++) {
//         int sum1 = 0, sum2 = 0; // sum of the first and second subarray
    
//         for(int j = 0; j <= i; j++) {
//             sum1 += arr[j]; // sum of the first subarray
//         }

//         for(int k = i + 1; k < n; k++) {
//             sum2 += arr[k]; // sum of the second subarray
//         }
//         if(sum1 == sum2) {
//             cout << "The two subarrays are equal" << endl;
//         }
//         else {
//             cout << "The two subarrays are not equal" << endl;
//         }
//     }
    
//     return 0;
// }

// 2 Approach having O(n) complexity
// In this approach we will use the totalSum which calculates the sum of the array and 
//then we will use the prefix sum to calculate the sum of the first subarray and then we will check if the sum of the first subarray is equal to the totalSum - sum of the first subarray.
// If it is equal then we will print that the two subarrays are equal otherwise we will print that they are not equal.

int main() {
    int arr[] = {3, 4, -2, 5, 8, 20, -10, 8};
    int n = sizeof(arr)/ sizeof(arr[0]); // size of the array

    // Calculate the total sum of the array
    int totalSum = 0;
    for(int i = 0; i < n; i++) {
        totalSum+= arr[i]; // sum of the array
    }

    for(int j = 0; j < n - 1; j++) {
        int prefixSum = 0; // sum of the first subarray

        for(int k = 0; k <= j; k++) {
            prefixSum += arr[k]; // sum of the first subarray
        }

        if(prefixSum == totalSum - prefixSum) {
            cout << "The two subarrays are equal" << endl;
        }
        else {
            cout << "The two subarrays are not equal" << endl;
        }
    }
}