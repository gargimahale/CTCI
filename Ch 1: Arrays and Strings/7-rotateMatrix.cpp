#include <bits/stdc++.h>
using namespace std;

/*
Q. Given an image represented by an NxN matrix, where each pixel
in the image is 4 bytes, write a method to rotate the image
by 90 degrees. Can you do this in place?
*/

bool isRotation(vector<vector<int>>& mat) {
    int r = mat.size(), col = mat[0].size();
    if (row == 0 || row != col) return false;

    reverse(mat.begin(), mat.end());

    // transpose the matrix
    for (int i = 0; i < row; ++i) {
        for (int j = i + 1; j < col; ++j) {
            swap(mat[i][j], mat[j][i]);
        }
    }
    return true;
}

int main() {
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << isRotation(mat) << "\n";
    return 0;
}

// TC: O(N*M)
// SC: O(1)