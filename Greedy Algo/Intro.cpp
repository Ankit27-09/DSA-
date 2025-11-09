// Greedy Algorithm:- It is a problem solving approach that makes a sequence of choice , each of which looks best at that moment;
// This method aims to find global optimal solution by making series of locally optimal solution.

// 1. Problem is the Minimum Number of Coins

#include <iostream>
using namespace std;

/*
  Program: Minimum number of notes for a given amount
  Denominations used: 10, 5, 2, 1 (largest to smallest)
  Approach: Greedy (always take as many of the largest denomination as possible)
  Why greedy is OK here:
    - Denominations include 1, and this specific system (10,5,2,1) is canonical:
      taking the largest coins first yields an optimal (minimum-count) solution.
  Complexity:
    - Time: O(D) where D = number of denominations (here D = 4)
    - Space: O(1) (constant extra space)
*/

class Solution {
  public:
    /*
      findMin(n)
      ----------------
      Input:
        - n : integer amount to make using the currency notes
      Output:
        - minimum number of notes required to make amount n using {10,5,2,1}
      Steps (high-level):
        1. Have the denominations in descending order so we try largest first.
        2. For each denomination:
             a) compute how many notes of this denomination we can use (n / denom)
             b) add that count to the total
             c) reduce the remaining amount (n = n % denom)
        3. When remaining amount becomes 0 we are done (early exit).
        4. Return the accumulated count.
    */
    int findMin(int n) {
        // 1) Denominations sorted from largest to smallest
        int currency[] = {10, 5, 2, 1};

        // 2) This will hold the total number of notes we use
        int count = 0;

        // 3) Iterate over each denomination
        for (int i = 0; i < 4; ++i) {
            // If no amount remains, we can stop early (optimization)
            if (n == 0) break;

            // 3a) Maximum number of notes of current denomination we can use
            //      Example: if n = 27 and currency[i] = 10, notes = 2
            int notes = n / currency[i];

            // 3b) Add those notes to the total count
            count += notes;

            // 3c) Reduce the remaining amount by the value covered by these notes
            //      After this n will be strictly less than currency[i]
            n = n % currency[i];

            // Next iteration will try the next smaller denomination
        }

        // 4) Return the total number of notes used
        return count;
    }
};

int main() {
    Solution sol;
    int amount;

    // Read amount from standard input.
    // Example usage:
    //   echo 27 | ./a.out   -> prints 4
    //   (because 27 = 10 + 10 + 5 + 2 -> 4 notes)
    if (!(cin >> amount)) {
        cerr << "Please enter a valid integer amount.\n";
        return 1;
    }

    if (amount < 0) {
        cerr << "Amount cannot be negative.\n";
        return 1;
    }

    int minNotes = sol.findMin(amount);

    // Print result (just the number). You can modify to print a more verbose message.
    cout << minNotes << '\n';
    return 0;
}
