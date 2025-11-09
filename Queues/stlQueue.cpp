#include <iostream>
using namespace std;
#include <queue>
int main() {
    queue<int> q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(-12);
    q.push(3);

    q.pop();
    q.pop();

    cout << "The size of queue is " << q.size() << endl;
    // Front Element
    cout << "Front element is " << q.front() << endl; 

    // Back Element
    cout << "Back Element is" << q.back() << endl;

    cout << q.empty() << endl;
}