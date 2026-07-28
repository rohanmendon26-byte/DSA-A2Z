// Time: O(n) worst case, 
// O(log n) average case;
//  Space: O(1).


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target)
               return true;
            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low=low+1;
                high=high-1;
                continue;
            }

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid])
                   high=mid-1;
                else
                   low=mid+1;
            }

            else{
                if(nums[mid]<=target && target<=nums[high])
                   low=mid+1;
                else
                   high=mid-1;
            }
        }
        return false;
    }
};


// Example 1:
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true

// Example 2:
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false


// Input: arr[] = [3, 3, 3, 1, 2, 3], key = 3
// Output: true
// Explanation: 3 is present in the array.

// Input: arr[] = [4, 5, 8, 1, 1, 1, 2], key = 6
// Output: false
// Explanation: 6 is not present in the array.