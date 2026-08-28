// Time: O(n)
// Space: O(1)


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all=0;
        for(int num:nums){
            xor_all^=num;
        }

        long long mask=(long long)xor_all & -(long long)xor_all;
        int first_unique=0;
        int second_unique=0;

        for(int num:nums){
            if(num & mask)
               first_unique^=num;
            else
               second_unique^=num;
        }

        return{first_unique,second_unique};
    }
};


// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]
 