#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;
    int invCount = 0;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            // all remaining elements in left half (i...mid) are greater
            invCount += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[st + k] = temp[k];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end) {
    int invCount = 0;
    if (st < end) {
        int mid = st + (end - st) / 2;
        invCount += mergeSort(arr, st, mid);
        invCount += mergeSort(arr, mid + 1, end);
        invCount += merge(arr, st, mid, end);
    }
    return invCount;
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();
    int result = mergeSort(arr, 0, n - 1);
    cout << "Number of inversions are: " << result << endl;
    return 0;
}
