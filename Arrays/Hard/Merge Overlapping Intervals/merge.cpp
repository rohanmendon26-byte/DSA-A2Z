//Brute force
// Time: O(n²) (worst case)
// Space: O(n) (for the output)

#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> intervals)
{
    int n=intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<vector<int>> ans;
    for(int i=0;i<n;i++){
        int start=intervals[i][0];
        int end=intervals[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(intervals[j][0]<=end){
                end=max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

// Input: arr[][] = [[1, 3], [2, 4], [6, 8], [9, 10]]
// Output: [[1, 4], [6, 8], [9, 10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1, 3] and [2, 4] which on merging will become [1, 4]. Therefore we will return [[1, 4], [6, 8], [9, 10]].


// Input: arr[][] = [[6, 8], [1, 9], [2, 4], [4, 7]]
// Output: [[1, 9]]
// Explanation: In the given intervals all the intervals overlap with the interval [1, 9]. Therefore we will return [1, 9].

//Optimal solution
// Time Complexity = O(n log n)
// Space Complexity = O(n) (for storing the merged intervals)

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || arr[i][0]>ans.back()[1]){
                ans.push_back(arr[i]);
            }
            
            else{
                ans.back()[1]=max(ans.back()[1],arr[i][1]);
            }
        }
        return ans;
        
    }
};


// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// Example 3:

// Input: intervals = [[4,7],[1,4]]
// Output: [[1,7]]
// Explanation: Intervals [1,4] and [4,7] are considered overlapping.