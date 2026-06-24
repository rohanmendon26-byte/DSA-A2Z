class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0;
        int cnt2=0;
        int n=nums.size();
        int ele1=INT_MIN,ele2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && ele1!=nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1==nums[i]){
                cnt1++;
            }
            else if(ele2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int>ls;
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(ele1==nums[i]){
                cnt1++;
            }
            if(ele2==nums[i]){
                cnt2++;
            }
            }
            int mini=(int)(n/3)+1;
            if(cnt1>=mini){
                ls.push_back(ele1);
            }
            if(cnt2>=mini){
                ls.push_back(ele2);
            }
        
        return ls;
    }
};

 
// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]