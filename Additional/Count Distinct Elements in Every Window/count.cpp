class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int>ans;
        unordered_map<int,int>freq;
        
        for(int i=0;i<k;i++){
            freq[arr[i]]++;
        }
        
        ans.push_back(freq.size());
        
        for(int i=k;i<arr.size();i++){
            freq[arr[i-k]]--;
            if(freq[arr[i-k]]==0)
               freq.erase(arr[i-k]);
               
               
               
            freq[arr[i]]++;
            
            ans.push_back(freq.size());
        }
        return ans;
    }
};



// Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
// Output: [3, 4, 4, 3]
// Explanation:
// First window is [1, 2, 1, 3], count of distinct numbers is 3.
// Second window is [2, 1, 3, 4] count of distinct numbers is 4.
// Third window is [1, 3, 4, 2] count of distinct numbers is 4.
// Fourth window is [3, 4, 2, 3] count of distinct numbers is 3.

// Input: arr[] = [4, 1, 1], k = 2
// Output: [2, 1]
// Explanation:
// First window is [4, 1], count of distinct numbers is 2.
// Second window is [1, 1], count of distinct numbers is 1.

// Input: arr[] = [1, 1, 1, 1, 1], k = 3
// Output: [1, 1, 1]
// Explanation: Every window of size 3 in the array [1, 1, 1, 1, 1], contains only the element 1, so the number of distinct elements in each window is 1.