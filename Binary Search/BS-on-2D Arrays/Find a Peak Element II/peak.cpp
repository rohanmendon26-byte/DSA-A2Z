// O(n log m)
// O(1)

class Solution {
public:
    
    int maxrowindex(vector<vector<int>>& mat,int n,int m,int col){
        int maxrow=-1;
        int index=-1;
        for(int i=0;i<n;i++){
           if(mat[i][col]>maxrow){
              maxrow=mat[i][col];
              index=i;
           }
        }
        return index;
    }

    
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0,high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int rowindex=maxrowindex(mat,n,m,mid);
            int left=mid-1>=0?mat[rowindex][mid-1]:-1;
            int right=mid+1<m?mat[rowindex][mid+1]:-1;
            if(mat[rowindex][mid]>left && mat[rowindex][mid]>right){
                return{rowindex,mid};
            }
            else if(mat[rowindex][mid]<left)
                high=mid-1;
            else
                low=mid+1;
        }

        return{-1,-1};
    }
};

// Input: mat = [[1,4],[3,2]]
// Output: [0,1]
// Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.

// Input: mat = [[10,20,15],[21,30,14],[7,16,32]]
// Output: [1,1]
// Explanation: Both 30 and 32 are peak elements so [1,1] and [2,2] are both acceptable answers.