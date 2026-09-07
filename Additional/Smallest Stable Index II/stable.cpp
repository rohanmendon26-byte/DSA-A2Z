// Time Complexity: O(n)

// You have 3 loops:

// Build prefixmax → O(n)
// Build suffixmin → O(n)
// Find first stable index → O(n)
// Space Complexity: O(n)

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefixmax(n);
        vector<int>suffixmin(n);

        prefixmax[0]=nums[0];

        for(int i=1;i<n;i++){
            prefixmax[i]=max(prefixmax[i-1],nums[i]);
        }

        suffixmin[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--){
            suffixmin[i]=min(suffixmin[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            int instability=prefixmax[i]-suffixmin[i];

            if(instability<=k)
               return i;
        }

        return -1;

    }
};

// Example 1:
// Input: nums = [5,0,1,4], k = 3
// Output: 3
// Explanation:
// At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
// At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
// At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
// This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.

// Example 2:
// Input: nums = [3,2,1], k = 1
// Output: -1
// Explanation:
// At index 0, the instability score is 3 - 1 = 2.
// At index 1, the instability score is 3 - 1 = 2.
// At index 2, the instability score is 3 - 1 = 2.
// None of these values is less than or equal to k = 1, so the answer is -1.

// Example 3:
// Input: nums = [0], k = 0
// Output: 0
// Explantion:
// At index 0, the instability score is 0 - 0 = 0, which is less than or equal to k = 0. Therefore, the answer is 0.