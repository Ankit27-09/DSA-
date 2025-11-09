// Prefix Sum :-- 

#include <iostream> 
using namespace std;
#include <vector>
#include <algorithm> // for the sort function

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/ sizeof(arr[0]); // size of the array
    // To store the prefix sum we can use the vector to store the prefix sum

    vector<int> prefixSum(n);
    prefixSum[0] = arr[0]; // first element is same as the first element of the array
    for(int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i]; // prefix sum is the sum of the previous prefix sum and the current element
    }

    for(int i = 0; i < prefixSum.size(); i++) {
        cout << prefixSum[i] << " "; // print the prefix sum
    }
    return 0;
}