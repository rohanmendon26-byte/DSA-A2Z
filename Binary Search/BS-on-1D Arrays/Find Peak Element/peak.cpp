// It also runs in O(log n) time and O(1) space.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
           return 0;
        if(nums[0]>nums[1])
           return 0;
        if(nums[n-1]>nums[n-2])
           return n-1;
        int low=1,high=n-2;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
               return mid;
            else if(nums[mid]>nums[mid-1])
               low=mid+1;
            else if(nums[mid]>nums[mid+1])
               high=mid-1;
            else
               low=mid+1;
        }
        return -1;
        
    }
};

// Example 1:
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Example 2:
// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.