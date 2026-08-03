// For your Koko Eating Bananas solution:

// Time Complexity: O(n log M)

// Where:

// n = number of piles
// M = maximum number of bananas in any pile
// space is O(1)."


class Solution {
public:


    long long func(vector<int>&piles,int hours){
        long long totalh=0;
        for(int i=0;i<piles.size();i++){
            totalh+=ceil((double)piles[i]/(double)hours);
        }
        return totalh;
    }

    int maxele(vector<int>&piles){
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        return maxi;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=maxele(piles);
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalh=func(piles,mid);
            if(totalh<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
        
    }
};



// Example 1:
// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], h = 6
// Output: 23


// Input: arr[] = [5, 10, 3], k = 4
// Output: 5
// Explanation: If Koko eats at the rate of 5 bananas per hour:
// First pile of 5 bananas will be finished in 1 hour.
// Second pile of 10 bananas will be finished in 2 hours.
// Third pile of 3 bananas will be finished in 1 hours.
// Therefore, Koko can finish all piles of bananas in 1 + 2 + 1 = 4 hours.

// Input: arr[] = [5, 10, 15, 20], k = 7
// Output: 10
// Explanation: If Koko eats at the rate of 10 bananas per hour, it will take 6 hours to finish all the piles.