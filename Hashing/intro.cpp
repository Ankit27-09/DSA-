/* What is Hashing ?
It is a technique which is used in data structure to store and retrieve data efficiently.
Hashing involves mapping data to a specific index in a hash table (an array of items) using a hash function. It enables fast retrieval of information based on its key.
The great thing about hashing is, we can achieve all three operations (search, insert and delete) in O(1) time on average.
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0}; // hash table
    for(int i = 0; i < n; i++) {
        hash[arr[i]] += 1; // increment the frequency of arr[i]
    }
    int q; // number of queries
    cin >> q;
    while(q--) {
        int key; // element to be searched
        cin >> key;
        cout << hash[key] << endl; // print the frequency of key
    }
}

// The time complexity of storing and fetching in the unordered map is o(log n) in worst case and o(1) in average case.
// The space complexity is o(n) as we are using an extra array of size n.