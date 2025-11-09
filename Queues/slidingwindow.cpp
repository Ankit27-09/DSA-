#include <iostream>
using namespace std;
#include <queue>
// Ques-1 Prnt all the number in every windpow of size k..

 void display(queue<int> q) {
    while(!q.empty()) {
        cout << q.front();
        q.pop();
    }
    cout << endl;
 }

 int main() {
    int arr[] = {2,3,1,5,6,7,8};
    int n = 7;
    int k = 3;

    queue<int>q;
    // k - 1 elements ko push kard do queue ke andar
    for(int i = 0; i < k-1; i++) {
        q.push(arr[i]);
    }

    for(int i = k - 1; i < n; i++ ) {
        q.push(arr[i]);
        display(q);
        q.pop();
    }
    return 0;
 }

 // first negative interger in every window of size
 

