// Print all the elements in a queue...

// #include <iostream>
// using namespace std;
// #include <queue>

// int main() {
//     queue <int> q;
//     q.push(5);
//     q.push(23);
//     q.push(12);
//     q.push(10);

//     // value Print karwao
//     int n = q.size();
//     while(n--) {
//         cout << q.front() << " ";
//         q.push(q.front());
//         q.pop();
//     }

//     cout << q.size();
// }

//  Queue Reversal

//Function to reverse the queue.

// class Solution
// {
//     public:
//     queue<int> rev(queue<int> q)
//     {
//         stack<int> st;
//         // Empty the queue into the stack
//         while(!q.empty()) {
//             st.push(q.front());
//             q.pop();
//         }
//         // Empty the stack back into the queue
//         while(!st.empty()) {
//             q.push(st.top());
//             st.pop();  // Pop the top element after pushing it to the queue
//         }
//         return q;
//     }
// };

// First reverse K element from the queue
//  User function Template for C++

// class Solution
// {
//     public:
    
//     // Function to reverse first k elements of a queue.
//     queue<int> modifyQueue(queue<int> q, int k) {
//         stack<int> st;
//         while(k--) {
//             st.push(q.front());
//             q.pop();
//         }
//         int n = q.size();
//         while(!st.empty()) {
//             // Queue ke andar daaldo, reverse order
//             q.push(st.top());
//             st.pop();  
//         }
//         while(n--) {
//             q.push(q.front());
//             q.pop();
//         }
//         return q;
//     }
// };

// //{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t-- > 0) {
//         int n, k;
//         cin >> n >> k;
//         queue<int> q;
//         while (n-- > 0) {
//             int a;
//             cin >> a;
//             q.push(a);
//         }
//         Solution ob;
//         queue<int> ans = ob.modifyQueue(q, k);
//         while (!ans.empty()) {
//             int a = ans.front();
//             ans.pop();
//             cout << a << " ";
//         }
//         cout << endl;
//     }
// }