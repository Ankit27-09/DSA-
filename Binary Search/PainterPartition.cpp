class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        // ✅ Base case: If there are more painters than boards,
        // then it's not possible (each painter must get at least 1 board).
        if (k > arr.size()) {
            return -1;
        }

        int ans = 0;

        // ✅ 'start' should be the maximum board length
        // (because at least one painter must paint the longest board).
        int start = *max_element(arr.begin(), arr.end());

        // ✅ 'end' should be the sum of all boards
        // (because if there's only one painter, they must paint all boards).
        int end = accumulate(arr.begin(), arr.end(), 0);

        // ✅ Binary Search between [start, end]
        // We're trying to minimize the maximum workload assigned to any painter.
        while (start <= end) {
            int mid = start + (end - start) / 2; // Proposed maximum workload

            int painters = 0; // Workload assigned to the current painter
            int count = 1;    // Number of painters used

            // ✅ Try to allocate boards to painters
            for (int i = 0; i < arr.size(); i++) {
                painters += arr[i];

                // If workload exceeds 'mid', give this board to a new painter
                if (painters > mid) {
                    count++;              // Increase painter count
                    painters = arr[i];    // Start workload for the new painter
                }
            }

            // ✅ If painters needed <= k,
            // it means this workload (mid) is possible, so try for smaller maximum
            if (count <= k) {
                ans = mid;       // Store the possible answer
                end = mid - 1;   // Try to minimize further
            }
            // ✅ If painters needed > k,
            // it means 'mid' is too small, so increase workload
            else {
                start = mid + 1;
            }
        }

        // ✅ Return the minimum time (i.e., minimized maximum workload)
        return ans;
    }
};

// ------------------ DRIVER CODE ------------------
int main() {
    Solution s;
    vector<int> boards = {10, 20, 30, 40}; // Each board's length
    int k = 2; // Number of painters

    cout << "Minimum time required: " << s.minTime(boards, k) << endl;
    return 0;
}