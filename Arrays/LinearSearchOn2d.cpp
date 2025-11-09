// Linear search on 2d array is a simple task.
// We just need to iterate over the rows and columns and compare the element with the target element.
// If the element is found, we return the index of the element. If the element is not found, we return -1.

#include <iostream>
using namespace std;

int main() {
    int key = 8;
    int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int row = 3;
    int col = 3;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(matrix[i][j] == key) {
                cout << "Element found at index: " << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
