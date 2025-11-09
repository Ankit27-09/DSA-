
// In C++, list container implements a doubly linked list in which each element contains the address of next and previous element in the list.
// It stores data in non-contiguous memory, hence providing fast insertion and deletion once the position of the element is known.

// Syntax

// list<data type> name_of_list;

// list<int> l1;
// list<string> l2;

// Basic Operation on List

// 1.) Insertion at beginning or end can be done by push_front() and push_back() respectively.
// 2.) Deletion at beginning or end can be done by pop_front() and pop_back() respectively.
// 3.) To insert an element at a particular position, insert() function is used.
// 4.) To delete an element at a particular position, erase() function is used.
// 5.) To quickly access the first and lasdt elements can be done using front() and back() respectively.
// 6.) To remove all the elements from the list, clear() function is used.


#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l1;
    int arr[] = {1,2,3,4,5};
    for(int i = 0; i < 5; i++) {
        l1.push_back(arr[i]);
        l1.push_front(arr[i]);
    }

    // for(int i = 0; i < 10; i++) 
    // {
    //     cout << l1.front() << " ";
    //     l1.pop_front();
    // }
    l1.clear();

    cout << l1.front();
}