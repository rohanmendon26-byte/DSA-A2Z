//Two sum(Better approach) -- returning indexes
//Time complexity(O(nlogn))

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=nums[i];
            int more=target-a;
            if(mpp.find(more)!=mpp.end()){
                return{mpp[more],i};
            }
            mpp[a]=i;
        }
        return{-1,-1};
    }
};



// Two sum(optimal approach) --returning yes or no
int left=0,right=n-1;
sort(book.begin(),book.end());

while(left<right){
    sum=book[left]+book[right];
    if(sum==k){
        return "yes";
    }

    else if(sum<target){
        left++;
    }

    else{
        right++;
    }
}
return "no";