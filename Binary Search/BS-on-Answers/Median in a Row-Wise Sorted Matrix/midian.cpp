// Time Complexity: O(n log m log(max-min))
// Space Complexity: O(1)

class Solution {
  public:
    
    int upper_bound(vector<int> &mat,int m,int x){
        int low=0,high=m-1,ans=m;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mat[mid]>x){
               ans=mid;
               high=mid-1;
            }
            else
               low=mid+1;
        }
        return ans;
    }
  
  
    int countsmallequals(vector<vector<int>> &mat,int n,int m,int x){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(mat[i],m,x);
        }
        return cnt;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int low=INT_MAX,high=INT_MIN;
        for(int i=0;i<n;i++){
            low=min(low,mat[i][0]);
            high=max(high,mat[i][m-1]);
        }
        int req=(m*n)/2;
        while(low<=high){
            int mid=low+(high-low)/2;
            int smallequals=countsmallequals(mat,n,m,mid);
            if(smallequals<=req)
              low=mid+1;
            else
               high=mid-1;
        }
        return low;
    }
};


// Input: mat[][] = [[1, 3, 5], [2, 6, 9], [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.

// Input: mat[][] = [[2, 4, 9], [3, 6, 7], [4, 7, 10]]
// Output: 6
// Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.

// Input: mat = [[3], [4], [8]]
// Output: 4
// Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.