
//Time->O(n)
//Space->O(n)



class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        unordered_map<int,int>mpp;
        
        int sum=0;
        int maxi=0;
        
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            if(sum==0){
                maxi=i+1;
            }
            
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return maxi;
    }
};


// Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [-2, 2, -8, 1, 7].

// Input: arr[] = [2, 10, 4]
// Output: 0
// Explanation: There is no subarray with a sum of 0.

// Input: arr[] = [1, 0, -4, 3, 1, 0]
// Output: 5
// Explanation: The longest subarray with sum equals to 0 is [0, -4, 3, 1, 0]