#include <iostream>
using namespace std;
#include <vector>

int merge(vector<int>&arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    vector<int> temp;
    int invCount = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid - i + 1);
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }
    for(int index = 0; index < temp.size(); index++) {
        arr[start + index] = temp[index];
    }
    return invCount;
}

int mergeSort(vector<int>& arr, int start, int end) {
    if(start < end) {
        int mid = start + (end - start) / 2;
        int leftInversionsCount = mergeSort(arr, start, mid);
        int rightInversionsCount = mergeSort(arr, mid + 1, end);
        
        int invCount = merge(arr, start, mid, end);
        return leftInversionsCount + rightInversionsCount + invCount; 
    }
    return 0;
}
int main() {
    vector<int> arr = {6,3,5,2,7};
    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "Number of inversions: " << ans << endl;
    return 0;
}