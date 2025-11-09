#include <iostream>
using namespace std;
#include <stack>



int main() {
stack<int> s;

s.push(5);
s.push(1);
s.push(3);
s.pop();
s.pop();

cout << s.size() << endl;
cout << s.top() << endl;
}