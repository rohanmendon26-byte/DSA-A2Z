//Only one solution exists that is Optimal
//Time Complexity--> O(n*n)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> ans;
        int top=0,bottom=n-1;
        int left=0,right=m-1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            }

            if(left<=right){
            for(int i=bottom;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
            }
        }
        return ans;
        
    }
};


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]



//Spiral fill
//Time Complexity-->O(n*m)
class Solution {
public:
    vector<vector<int>> spiralFill(int n, int m, vector<int> &arr) {
        
        vector<vector<int>>mat(n,vector<int>(m));

        int top = 0, bottom = n - 1;
        int left = 0, right = m - 1;

        int idx = 0;

        while (top <= bottom && left <= right) {

         
            for (int j = left; j <= right; j++) {
                mat[top][j] = arr[idx++];
            }
            top++;

        
            for (int i = top; i <= bottom; i++) {
                mat[i][right] = arr[idx++];
            }
            right--;

         
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    mat[bottom][j] = arr[idx++];
                }
                bottom--;
            }

         
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    mat[i][left] = arr[idx++];
                }
                left++;
            }
        }

        return mat;
    }
};

// Input: n = 4, m = 4, arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]
// Output: [[1, 2, 3, 4],
//         [12, 13, 14, 5],
//         [11, 16, 15, 6],
//         [10, 9, 8, 7]]