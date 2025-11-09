// Question Link ->  https://leetcode.com/problems/online-stock-span/description/

#include <iostream>
#include <stack>
using namespace std;
#include <vector>
/*
   📘 Problem: Online Stock Span
   Goal:
   For each day’s stock price, we must return the number of consecutive
   days (including today) the stock price was <= today's price.

   💡 Intuition:
   - Use a stack to keep track of (price, span)
   - For each new price:
        1. Pop all prices <= current price.
        2. Add up their spans.
        3. Push (current price, total span) back into the stack.
   - The stack ensures prices remain in decreasing order.
*/

class StockSpanner {
public:
    // Stack will store pairs of (price, span)
    stack<pair<int, int>> st;

    // Constructor
    StockSpanner() {
        // No need to initialize anything special
    }

    int next(int price) {
        // Start with a span of 1 (today itself)
        int span = 1;

        /*
            🔁 While the current price is greater or equal to the
            top of the stack's price, it means the current price
            continues the span of those previous days.

            Example:
            stack = [(100,1), (80,1), (60,1), (70,2)]
            next(75):
                -> pop (70,2)
                -> pop (60,1)
                Total span = 1 (today) + 2 + 1 = 4
        */
        while (!st.empty() && st.top().first <= price) {
            span += st.top().second;  // Add the span of popped price
            st.pop();
        }

        // Push current price and its calculated span
        st.push({price, span});

        // Return span for today's price
        return span;
    }
};

/*
   🧠 Example Dry Run:

   Input:
   prices = [100, 80, 60, 70, 60, 75, 85]

   Step by step:
   next(100) -> stack = [(100,1)] -> span = 1
   next(80)  -> stack = [(100,1),(80,1)] -> span = 1
   next(60)  -> stack = [(100,1),(80,1),(60,1)] -> span = 1
   next(70)  -> pop(60,1) -> stack = [(100,1),(80,1)] -> span = 2
   next(60)  -> stack = [(100,1),(80,1),(60,1)] -> span = 1
   next(75)  -> pop(60,1), pop(70,2) -> stack = [(100,1),(80,1)] -> span = 4
   next(85)  -> pop(80,1), pop(75,4) -> stack = [(100,1)] -> span = 6
*/

/*
   🕒 Time Complexity:
   - Each price is pushed and popped at most once.
   - Amortized O(1) per operation.

   🧮 Space Complexity:
   - O(N) for the stack in the worst case (strictly decreasing prices).
*/

int main() {
    // Example usage for understanding (you can remove this before submission)
    StockSpanner stockSpanner;
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};

    for (int price : prices) {
        cout << "Price: " << price
             << " -> Span: " << stockSpanner.next(price) << endl;
    }

    return 0;
}
