// Time:O(n)
// Space:O(n)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool>arr(n,false);
        
        for(int num:nums){
            if(num>0 && num<=n){
                arr[num-1]=true;
            }
        }
        
        for(int i=0;i<n;i++){
            if(!arr[i]){
                return i+1;
            }
        }
        
        return n+1;
    }
};

// Example 1:

// Input: nums = [1,2,0]
// Output: 3
// Explanation: The numbers in the range [1,2] are all in the array.
// Example 2:

// Input: nums = [3,4,-1,1]
// Output: 2
// Explanation: 1 is in the array but 2 is missing.
// Example 3:

// Input: nums = [7,8,9,11,12]
// Output: 1
// Explanation: The smallest positive integer 1 is missing.