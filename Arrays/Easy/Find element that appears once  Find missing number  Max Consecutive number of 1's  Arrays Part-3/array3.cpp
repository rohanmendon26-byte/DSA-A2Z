//Find the missing number is array
class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n=nums.size();
       int sum=n*(n+1)/2;
       int s2=0;
       for(int i=0;i<n;i++){
        s2=s2+nums[i];
       }

       return sum-s2;
    }
};

// Input: nums = [3,0,1]
// Output: 2


//Maximum Consecutive Ones
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=0;
            }
        }
        return maxi;
    }
};

// Input: nums = [1,1,0,1,1,1]
// Output: 3


// find-the-number-that-appears-once-and-the-other-numbers-twice(optimal)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor1=0;
        for(int i=0;i<nums.size();i++){
            xor1=xor1^nums[i];
        }
        return xor1;
    }
};

// Input: nums = [4,1,2,1,2]
// Output: 4