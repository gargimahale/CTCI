#include <bits/stdc++.h>
using namespace std;

/*
Q. Given an image represented by an NxN matrix, where each pixel 
in the image is 4 bytes, write a method to rotate the image 
by 90 degrees. Can you do this in place?
*/

bool isRotation(vector<vector<int>>& mat){
    if (mat.size() == 0 || mat.size() != mat[0].size) return false;

    int n = mat.size();
    
    reverse(mat.begin(), mat.end());

    // transpose the matrix
    for(int i = 0; i<mat.size(); ++i){
        for (int j = i+1; j<mat[0].size(); ++j){
            swap(mat[i][j], mat[j][i]);
        }
    }
    return true;
}

int main(){
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << isRotation(mat) << "\n";
    return 0;
}