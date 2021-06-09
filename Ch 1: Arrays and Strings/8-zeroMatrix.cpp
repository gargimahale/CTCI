#include <bits/stdc++.h>
using namespace std;

/*
Q. Write an algorithm such that if an element in an MxN matrix is 0,
its entire row and column are set to 0.
*/

void setZeroes(vector<vector<int>>& matrix) {
    bool isZeroCol = false;
    bool isZeroRow = false;

    // check the first column
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            isZeroCol = true;
            break;
        }
    }

    // check the first row
    for (int i = 0; i < matrix[0].size(); i++) { //check the first row
        if (matrix[0][i] == 0) {
            isZeroRow = true;
            break;
        }
    }

    // check execpt the first row and col
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
    }

    // turn zero except first row and first col
    for (int i = 1; i < matrix.size(); i++) { //process except the first row and column
        for (int j = 1; j < matrix[0].size(); j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    }

    // handle first col
    if (isZeroCol) {
        for (int i = 0; i < matrix.size(); i++)
            matrix[i][0] = 0;
    }

    //handle first row
    if (isZeroRow) {
        for (int i = 0; i < matrix[0].size(); i++)
            matrix[0][i] = 0;
    }
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    setZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j  = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// TC: O(N*M), SC: O(1)