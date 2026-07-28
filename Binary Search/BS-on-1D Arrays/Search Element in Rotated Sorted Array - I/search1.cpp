
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
               return mid;

            //left sorted
            else if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid])
                   high=mid-1;
                else
                   low=mid+1;
            }
            //right sorted
            else{
                if(nums[mid]<=target && target<=nums[high])
                   low=mid+1;
                else
                   high=mid-1;
            }
        }
        return -1;
    }
};


// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1