// set in cpp STL

// In C++, sets are associative container which stores unique elements in some sorted order. 
// By default, it is sorted ascending order of the keys, but this can be changes as per requirement. 
//It provides fast insertion, deletion and search operations.
// Generally implmented using Red-Black Tree.

// Syntax
// set<data type> name_of_set;

// Use Cases:
// 1. When you want to store unique elements in sorted order.
// 2. When you want to store elements in sorted order and want to perform search, insert and delete operations in O(log n) time complexity.

// set<int> s;
// s.insert(1);
// s.insert(2);
// s.insert(3);
// s.insert(4);
// s.insert(1); // It will not be inserted as it is already present in the set

#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    s.insert(1);
    s.insert(22);
    s.insert(30);
    s.insert(4);
    s.insert(1); // It will not be inserted as it is already present in the set

    for(auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
}