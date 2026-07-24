// Complexity
// Time: O(n)
// Space: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int prefix=1,suffix=1;
        for(int i=0;i<n;i++){
            if(prefix==0)
               prefix=1;
            if(suffix==0)
               suffix=1;
            prefix=prefix*nums[i];
            suffix=suffix*nums[n-i-1];
            ans=max(ans,max(prefix,suffix));
        }
        return ans;  
    }
};


// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is [6, -3, -10] with product = 6 * (-3) * (-10) = 180.

// Input: arr[] = [-1, -3, -10, 0, 6]
// Output: 30
// Explanation: The subarray with maximum product is [-3, -10] with product = (-3) * (-10) = 30.

// Input: arr[] = [2, 3, 4] 
// Output: 24 
// Explanation: For an array with all positive elements, the result is product of all elements. 