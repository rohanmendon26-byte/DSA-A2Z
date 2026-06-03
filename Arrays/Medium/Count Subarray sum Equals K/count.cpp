//Time complexity--> O(nlogn)
//Space complexity--> O(n) --> mpp stores n prefix sums
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        mpp[0]=1;
        int presum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int remove=presum-k;
            count+=mpp[remove];
            mpp[presum]+=1;
        }

        return count;
    }
};


// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2