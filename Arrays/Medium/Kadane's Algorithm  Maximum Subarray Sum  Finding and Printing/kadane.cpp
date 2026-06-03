//Time-Complexity--> O(N)
//Space-Complexxity--> O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            if(sum > maxi){
                maxi=sum;
            }

            if(sum < 0){
                sum=0;
            }
        }
        return maxi;
        
    }
};

// nums = [-2,1,-3,4,-1,2,1,-5,4]
// 6
