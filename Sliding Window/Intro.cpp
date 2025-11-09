// This is the Brute Force Approach
// Time Complexity: O(n^3)
// Space Complexity: O(n)

#include <iostream>
using namespace std;
#include <vector>

int main() {
    int n = 10; // Example size
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> vc;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                    vc.push_back(arr[i] + arr[j] + arr[k]);
                    cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
            }
        }
    }
    int maxi  = -99999;
    for(int i = 0; i < vc.size(); i++) {
        maxi = max(maxi, vc[i]);
    }
    cout << "Maximum value among found elements: " << maxi << endl;
    return 0;

}