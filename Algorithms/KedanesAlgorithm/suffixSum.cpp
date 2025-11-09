// #Suffix Sum :--

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm> // for the sort function

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]); // size of the array
    // To store the suffix sum we can use the vector to store the suffix sum

    vector<int> suffixSum(n);
    suffixSum[n - 1] = arr[n - 1]; // last element is same as the last element of the array

    for(int i = n - 2; i >= 0; i--) {
        suffixSum[i] = suffixSum[i + 1] + arr[i]; // suffix sum is the sum of the next suffix sum and the current element
    }

    for(int i = 0; i < suffixSum.size(); i++) {
        cout << suffixSum[i] << " "; // print the suffix sum
    }
    cout << endl; // for better readability
}