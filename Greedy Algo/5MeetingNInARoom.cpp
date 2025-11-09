#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // ✅ Comparator function for sorting meetings by their end time
    // - We mark it as `static` because `sort()` expects a standalone function pointer,
    //   not a member function that depends on an object.
    static bool comp(const pair<int, int>& a, const pair<int, int>& b) {
        // Sort by end time in ascending order
        return a.second < b.second;
    }

    // ✅ Function to find the maximum number of non-overlapping meetings
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size(); // total number of meetings
        
        // Step 1: Store each meeting as a pair {start, end}
        vector<pair<int, int>> timer;
        for(int i = 0; i < n; i++) {
            timer.push_back({start[i], end[i]});
        }
        
        // Step 2: Sort the meetings based on end time (earliest finishing first)
        sort(timer.begin(), timer.end(), comp);
        
        // Step 3: Greedy selection of meetings
        int endTime = -1;  // stores the end time of the last selected meeting
        int total = 0;     // counts how many meetings we can attend
        
        for(int i = 0; i < n; i++) {
            // If the current meeting starts after the last meeting finished
            if(timer[i].first > endTime) {
                total++;                  // we can attend this meeting
                endTime = timer[i].second; // update last ending time
            }
        }
        
        // Step 4: Return the total number of meetings selected
        return total;
    }
};

int main() {
    Solution sol;
    
    // Example Input
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    
    cout << sol.maxMeetings(start, end) << endl; // Expected Output: 4
    
    return 0;
}
