//for single transaction
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini=prices[0];
    int maxprofit=0;
    int n=prices.size();
    for(int i=1;i<n;i++){
         int cost=prices[i]-mini;
         maxprofit=max(maxprofit,cost);
         mini=min(mini,prices[i]);
    }
    return maxprofit;
}
// Sample Input 1:
// 1 2 3 4
// Sample Output 1:
// 3

//for multiple transaction
class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int mini=arr[0];
        int profit=0;
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                profit+=arr[i]-arr[i-1];
            }
        }
        return profit;
    }
};

// Input: arr[] = [100, 180, 260, 310, 40, 535, 695]
// Output: 865