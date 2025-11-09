// Map in C++ STL

// In C++, maps are associative containers that store data in the form of key value pairs sorted on the basis of keys. No two mapped values can have the same keys. By default, it stores data in ascending order of the keys, but this can be changes as per requirement.

// keys are unique and are stored in sorted order, so that the search, insert and delete operations can be done in O(log n) time complexity.

// Syntax

// map<data type of key, data type of value> name_of_map;

// O(logn) time complexity making them fast for most use cases;

// It includes Red-black tree or AVL tree for implmentation.

#include <iostream>
#include <map>
using namespace std;

// int main() {
//     // map create
//     map<int, string> m;
//     // Insert the values in map witht the use of insert function

//     m.insert(make_pair(1, "Ankit"));
//     m.insert(make_pair(2, "Ankit"));
//     m.insert(make_pair(3, "Ankit"));
//     m.insert(make_pair(4, "Ankit"));
//     m.insert(make_pair(5, "Ankit"));

//     // Insert kar sakte ho value ko, update bhi kardeta hai 
//     m[100] = "Ankit";


//     for(auto it = m.begin(); it != m.end(); it++) {
//         cout << it->first << " " << it->second << endl;
//     }

//     if(m.count(200)) {
//         cout << "Present";
//     } else {
//         cout << "Not Present";
//     }

//     // erase
//     m.erase(100);

//     // multimap:-- multiple values with same key
//     // It is used to store multiple values with same key

//     multimap<int, string> mm;

//     mm.insert(make_pair(1, "Ankit"));

//     m[1] = "Ankit"; // It iss nott possible in multimap but possible in map
    
// }

// Unordered Map

// Unordered Map in C++ STL

// In C++, unordered_map is an unordered associative container that stores data in the form of unique key-value pairs.
//  But unlike map, unordered map stores its elements using hashing. This provides average constant-time complexity O(1) for search, insert, and delete operations but the elements are not sorted in any particular order.

// Unique key is present but duplicate keys are not allowed
// But ordered is not sorted
// Implemented using hashing
// Syntax
// Insert, delete, are done in constant time



int main() {
    unordered_map <int, int> um;

    um.insert(make_pair(1, 10));
    um.insert(make_pair(2, 20));
    um.insert(make_pair(3, 30));

    um[2] = 40;

    for(auto it = um.begin(); it != um.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}