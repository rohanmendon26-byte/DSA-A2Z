// Time Complexity: O(n) for each call to atMostKDistinct.
// Space Complexity: O(1) map size bounded by 26 characters for alphabets.

class Solution {
public:

    int atmostDistinct(vector<int>& nums, int k) {
        int left=0;
        int res=0;

        unordered_map<int,int>freq;

        for(int right=0;right<nums.size();right++){

            freq[nums[right]]++;

            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0)
                   freq.erase(nums[left]);
                left++;
            }

            res+=(right-left+1);
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmostDistinct(nums,k)-atmostDistinct(nums,k-1);
    }
};




// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]


// Input: nums = [1,2,1,3,4], k = 3
// Output: 3
// Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].