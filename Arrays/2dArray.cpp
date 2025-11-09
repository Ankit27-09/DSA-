// 2D array is also called the matrix
// 2D array is a collection of rows and columns

// int matrix[3][3] = { // 3x3 matrix
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9}
//     {1, 2, 3},
//     {4, 5, 6},
//     {7, 8, 9},
// };


// 2 d array is stored in memory in row major order and column major order
// Row major order: 1 2 3 4 5 6 7 8 9
// Column major order: 1 4 7 2 5 8 3 6 9


#include <iostream>
using namespace std;

int main() {
    // int arr[5] = {1,23,4,3,5};

    int matrix[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
    int row = 4;
    int col = 3;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }   
}