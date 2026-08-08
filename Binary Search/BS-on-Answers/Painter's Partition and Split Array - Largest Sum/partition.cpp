class Solution {
public:
    
    int countstudent(vector<int>& nums, int mid){
        int students=1,pagestudents=0;
        for(int i=0;i<nums.size();i++){
            if(pagestudents+nums[i]<=mid)
              pagestudents+=nums[i];
            else{
                students+=1;
                pagestudents=nums[i];
            }
        }
        return students;
    }
    
    
    
    int splitArray(vector<int>& nums, int k) {
       int low=*max_element(nums.begin(),nums.end());
       int high=accumulate(nums.begin(),nums.end(),0);
       while(low<=high){
        int mid=low+(high-low)/2;
        int student=countstudent(nums,mid);
        if(student>k)
           low=mid+1;
        else
           high=mid-1;
       } 
       return low;
    }
};




// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.