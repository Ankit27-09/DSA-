// Question link -> https://leetcode.com/problems/asteroid-collision/

// Time and Space Complexity:
// Time Complexity: O(n) - Each asteroid is pushed and popped at most once.
// Space Complexity: O(n) - In the worst case, all asteroids could survive and be stored in the stack.
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;         // will store the asteroids that are still moving/survived
        vector<int> ans;       // final result (we'll build from the stack)

        for (int i = 0; i < (int)asteroids.size(); i++) {
            int curr = asteroids[i];

            // If asteroid is moving right (positive), no immediate collision -> push it
            if (curr > 0) {
                st.push(curr);
            } 
            else { // curr < 0 -> asteroid moving left, possible collisions with stack's positive asteroids
                bool destroyed = false; // will become true if current asteroid gets destroyed

                // Collisions happen only while there is a right-moving asteroid on stack
                while (!st.empty() && st.top() > 0) {
                    int topVal = st.top();

                    if (topVal < abs(curr)) {
                        // top asteroid is smaller: it explodes, remove it and continue checking
                        st.pop();
                        continue; // keep checking with the next top (if any)
                    } 
                    else if (topVal == abs(curr)) {
                        // equal sizes: both explode
                        st.pop();
                        destroyed = true; // current also destroyed
                        break;
                    } 
                    else {
                        // topVal > abs(curr) -> top survives, current destroyed
                        destroyed = true;
                        break;
                    }
                }

                // If current asteroid survived (no right-moving asteroid left to collide),
                // push it onto the stack (it can be negative or zero - but zero won't occur here)
                if (!destroyed) {
                    st.push(curr);
                }
            }
        }

        // Convert stack to vector in correct order (stack top is rightmost)
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> result = sol.asteroidCollision(asteroids);

    cout << "Remaining Asteroids after Collisions: ";
    for (int asteroid : result) {
        cout << asteroid << " ";
    }
    cout << endl;

    return 0;
}