// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[low]<=nums[high]){
                ans=min(ans,nums[low]);
                break;
            }

            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};


// Example 1:
// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.

// Example 2:
// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

// Example 3:
// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 


// Input: arr[] = [5, 6, 1, 2, 3, 4]
// Output: 1
// Explanation: 1 is the minimum element in the array.

// Input: arr[] = [3, 1, 2]
// Output: 1
// Explanation: Here 1 is the minimum element.

// Input: arr[] = [4, 2, 3]
// Output: 2
// Explanation: Here 2 is the minimum element.