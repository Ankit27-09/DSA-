/*
Time complezity is O(n * n!) where n is the size of the input array.

🔍 What Is the Problem?
We are given a list of numbers (like {1, 2, 3}), and we want to generate all possible unique orderings of these numbers. These are called permutations.

🧠 Core Idea: Recursive Tree + Backtracking
The process of generating permutations can be visualized like a decision tree where:

At each level of the tree, we choose one element to place in the current position.

We make sure we don’t reuse elements in the same permutation.

We recursively build each permutation, and once we reach the end (length == n), we store it.

Then we backtrack — undo the last choice and try a new option.

🧱 Step-by-Step Breakdown of the Approach
Step 1: Track the current state
We maintain:

A temporary list to build one permutation.

A way to remember which elements have already been used in the current build (e.g., a boolean visited array).

Step 2: Recursive Exploration (DFS-style)
We use a recursive function to build the permutation one element at a time.

At each recursive call:

We check if the current permutation is complete (i.e., same size as the input).

If yes, we store it and return.

Otherwise, we loop through all the elements in the input list:

If an element hasn’t been used yet:

We choose it.

Mark it as used.

Add it to our current permutation.

Recurse to fill the next position.

After returning, we un-choose it (backtrack).

Step 3: Backtracking
This is key. After each recursive call, we remove the last added element and mark it as unused, so the next iteration of the loop can try a different option.

This ensures that all combinations of elements are tried, and no choice is repeated in the same branch.

🧠 Example Tree (Input: {1, 2, 3})
Here’s a visual representation of the recursive tree:

less
Copy
Edit
                   []
           /        |         \
         1          2          3
       /  \        / \        /  \
     2     3     1   3      1    2
     |     |     |   |      |    |
     3     2     3   1      2    1
Each path from the root to a leaf is one permutation.
Total permutations = 3! = 6

🔁 Why This Works (and Efficiently)
We avoid revisiting the same number in one permutation using a visited flag.

Backtracking ensures we reuse memory and don’t recompute redundant things.

Recursive depth is equal to n (length of array), so this is very efficient for small n.

Time Complexity:

There are n! permutations.

Each permutation is built in O(n) time.

So total complexity = O(n × n!)

✨ Final Thought
This approach is elegant because it mirrors how you might logically generate permutations by hand:

Choose a number,

Lock it in place,

Choose the next number from the remaining,

Continue until done,

Then go back and try a new option.

That's recursion + backtracking in action.*/


#include <iostream>
using namespace std;
#include <vector>

void permute(int arr[], vector<vector<int>> &ans, vector<int> &temp, vector<bool> &visited) {
    if (visited.size() == temp.size()) {
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            temp.push_back(arr[i]);
            permute(arr, ans, temp, visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

int main() {
    int arr[] = {1,2,3};
    vector<vector<int>> ans;

    vector<int> temp;

    vector<bool> visited(3, 0);

    permute(arr, ans, temp, visited);
    for(int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
        
    }


}

// 2nd Approach by not using visited array and using swap
// time complexity is O(n * n!) where n is the size of the input array.
// This approach uses swapping to generate permutations without needing a visited array.
// space complexity is O(n) for the recursion stack and O(n!) for storing the permutations.
#include <iostream>
using namespace std;
#include <vector>

void permute(int arr[], vector<vector<int>> &ans, int index) {
    if (index == 3) {
        vector<int> temp(arr, arr + 3);
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < 3; i++) {
        swap(arr[index], arr[i]);
        permute(arr, ans, index + 1);
        swap(arr[index], arr[i]); // backtrack
    }
} 