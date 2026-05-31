
class Solution {
    public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        //Time complexity--> O(n/2*n/2)
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //O(n/2)
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]


//for anticlockwise
// Time Complexity: O(N²)
// Space Complexity: O(1) (constant extra space)
#include <bits/stdc++.h> 
vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for(int j=0;j<n;j++){
        int top=0,bottom=n-1;

        while(top<bottom){
            swap(matrix[top][j],matrix[bottom][j]);
            top++;
            bottom--;
        }
    }

    return matrix;
    // Write your code here.
}

// For given 2D array :

//     [    [ 1,  2,  3 ],
//          [ 4,  5,  6 ],
//          [ 7,  8,  9 ]  ]

// After 90 degree rotation in anti clockwise direction, it will become:

//     [   [ 3,  6,  9 ],
//         [ 2,  5,  8 ],
//         [ 1,  4,  7 ]   ]