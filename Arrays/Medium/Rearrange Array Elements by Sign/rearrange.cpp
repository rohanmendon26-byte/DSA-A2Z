class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int posindex=0,negindex=1;
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                ans[negindex]=nums[i];
                negindex+=2;
            }
            else{
                ans[posindex]=nums[i];
                posindex+=2;
            }
        }
        return ans;
    }
};

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]


//Alternate numbers
vector<int> alternateNumbers(vector<int>&a){
    vector<int> pos,neg;
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]>0){
            pos.push_back(a[i]);
        }
        else{
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size()){
        for(int i=0;i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=neg.size()*2;
        for(int i=neg.size();i<pos.size();i++){
            a[index]=pos[i];
            index++
        }
    }

    else{
        for(int i=0;i<pos.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=pos.size()*2;
        for(int i=pos.size();i<neg.size();i++){
            a[index]=neg[i];
            index++
        }
    }
    return a;
}

// Input: nums = [1,2,-4,-5,3,6]
// Output: [1,-4,2,-5,3,6]