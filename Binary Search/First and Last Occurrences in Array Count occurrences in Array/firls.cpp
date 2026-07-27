// Why:

// lowerBound() runs in O(log n)
// upperBound() runs in O(log n)
// searchRange() calls both, so still O(log n) overall

// Space complexity is O(1) because you are using only a few extra variables.
class Solution {
public:
 int lowerBound(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

     int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=lowerBound(nums,target);
        if(lb==n || nums[lb]!=target)
            return{-1,-1};
        return {lb,upperBound(nums,target)-1};        
    }
};


// Example 1:

// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// Example 2:

// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// Example 3:

// Input: nums = [], target = 0
// Output: [-1,-1]



//without LB and UB
//First Occurrence in Sorted (Other problem)
// Complexity
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k){
                ans=mid;
                high=mid-1;
            }
            
            else if(arr[mid]<k){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};


//Last Occurence
class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k){
                ans=mid;
                low=mid+1;
            }
            
            else if(arr[mid]<k){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};
