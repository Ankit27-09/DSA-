#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        if(k > arr.size()) {
            return -1;
        }
         int ans = 0;
        int start = *max_element(arr.begin(), arr.end());
        int end = 0;
        
        for(int i = 0; i < arr.size(); i++) {
            end += arr[i];
        }
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            int pages = 0;
            int count = 1;
          
            for(int i = 0; i < arr.size(); i++) {
                pages += arr[i];
                if(pages > mid) {
                    count++;
                    pages = arr[i];
                }
            }
            
            if(count <= k) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> books = {12, 34, 67, 90};
    int students = 2;
    cout << "Minimum maximum pages = " << sol.findPages(books, students) << "\n"; // expected 113
    return 0;
}
Detailed explanation — every condition and why it’s there
Function signature
int findPages(vector<int> &arr, int k)

vector<int> &arr — passed by reference to avoid copying the vector (efficient).

k — number of students.

if(k > arr.size()) { return -1; }
What it checks: whether there are more students than books.

Why: Problem statement of this classical variant usually requires each student to get at least one book (contiguous chunk). If k > number_of_books, you cannot give each student at least one book, so allocation is impossible. Returning -1 is a common sentinel for "not possible".

Note: If the problem allowed some students to get zero books, this check would be removed.

int ans = 0;
Purpose: stores the best (minimum possible) value of the maximum pages per student found so far.

Why start at 0: We'll update ans only when we find a feasible mid. Initializing to 0 is fine because we overwrite it when a feasible value is found. (If no feasible value exists, other parts handle that; in your algorithm feasibility will be found because start begins at max_element and end at sum.)

int start = *max_element(arr.begin(), arr.end());
Meaning: start is the lower bound of our search space: the largest single book page count.

Why lower bound = largest book: Because books cannot be split, any valid maximum pages per student must be at least as big as the largest single book. You cannot allocate a book of x pages if the candidate maximum is < x.

Important subtlety: This line assumes arr is non-empty. Calling max_element on an empty vector is undefined behavior. (See pitfalls below.)

int end = 0; and the for loop summing end += arr[i];
Meaning: end is the upper bound of the search: sum of all pages (one student reads everything).

Why: If one student reads all books, that's the worst-case maximum pages any student gets. So the true answer lies between start and end inclusive.

while(start <= end) — binary-search on the answer space
What it does: binary-searches the space of possible "maximum pages per student".

Invariant: the true minimum feasible maximum lies in [start, end].

Loop termination: when start passes end, we’ve narrowed down to the smallest feasible value (stored in ans).

int mid = start + (end - start) / 2;
What: picks the middle candidate mid between start and end.

Why this form: start + (end - start) / 2 avoids overflow that might occur with (start + end) / 2 in some contexts. (With int it’s safer — though if sums are huge you should use long long — see suggestions.)

int pages = 0; int count = 1;
Meaning:

pages — total pages allocated to the current student while scanning books left-to-right.

count — number of students used so far (we start assigning to student 1).

Why start at count = 1: before starting the loop, we have at least the first student to allocate to.

Inner loop — greedy allocation:
cpp
Copy code
for(int i = 0; i < arr.size(); i++) {
    pages += arr[i];
    if(pages > mid) {
        count++;
        pages = arr[i];
    }
}
What happens: we iterate books in order (keeping contiguity).

We add the current book arr[i] to the current student’s pages.

If adding that book makes pages exceed mid, we allocate that book to the next student: increment count, and set pages = arr[i] (current book becomes the first book of the new student).

Why greedy works: for any fixed mid, the greedy approach that fills student 1 as much as possible (until it would exceed mid), then student 2, and so on, minimizes the number of students needed to keep per-student pages ≤ mid. This is the standard feasibility check for partitioning into contiguous subarrays under a maximum-sum constraint.

Contiguity preserved: because we only cut between books, never split a book — so each student’s assigned block remains contiguous.

if(count <= k) { ans = mid; end = mid - 1; } else { start = mid + 1; }
Interpretation:

If the greedy allocation uses count students less than or equal to allowed k students, then mid is a feasible maximum pages value.

We store it ans = mid because we want the minimum feasible maximum.

Then we attempt to find an even smaller feasible maximum by searching left: end = mid - 1.

Else (count > k): mid is too small — we needed more than k students to keep per-student pages ≤ mid. So increase allowed maximum: start = mid + 1.

Why this binary-step works: feasibility is monotonic: if some mid is feasible, any mid' > mid will also be feasible. That monotonicity enables binary search.

return ans;
After binary search completes, ans holds the minimal feasible maximum pages per student.

Time & space complexity
Time: Each feasibility check scans n books O(n). Binary search runs for O(log(end - start)) steps (roughly O(log(sum_of_pages))). Total O(n * log(sum)).

Space: O(1) extra (apart from input vector).

Example dry-run (quick)
Input: arr = {12, 34, 67, 90}, k = 2

start = 90 (largest book), end = 203 (sum). Binary search checks mid, greedily allocates and finds feasibility. Final ans = 113 (first student {12,34,67} = 113, second {90} = 90). This is the minimum possible maximum.

Pitfalls & suggested improvements (I did NOT change your code — these are suggestions)
Empty arr (undefined behavior): *max_element(arr.begin(), arr.end()) is undefined if arr is empty. Add at top:

cpp
Copy code
if (arr.empty()) return -1;
if your problem expects -1 for zero books.

Integer overflow for large inputs: if page counts and number of books are large, end (sum of pages) can overflow int. Safer to use long long for start, end, mid, pages, and ans. Example:

cpp
Copy code
long long start = *max_element(...);
long long end = accumulate(..., 0LL);
(I left your code as-is because you asked not to change it, but keep this in mind for large constraints.)

Comparison k > arr.size() uses signed/unsigned mix: arr.size() returns size_t. No functional issue normally, but you can cast/compare carefully to avoid warnings.

Return value when impossible: Your code returns -1 only when k > arr.size(). If arr is non-empty and k<=arr.size(), your algorithm will always find an answer (because start = max element, mid never < max element, so always feasible).

