#include <iostream>
#include <queue>
using namespace std;

int main() {
    // How to create a queue

    queue <int> q;
    q.push(5);
    q.push(522);
    q.push(51);
    // Delete
    q.pop();

    // front element
    cout << q.front() << endl; 

    // back eleemnt
    cout << q.back() << endl;

    // size queue
    cout << q.size();

    // Empty queue
    cout << q.empty();
}