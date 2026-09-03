//Time->O(n*log(logn))
//Space->O(n)


class Solution {
public:
    int countPrimes(int n) {
        if(n==0)
           return 0;
        vector<bool>ans(n,true);
        ans[0]=ans[1]=false;
        
        for(long long i=2;i*i<n;i++){
            if(!ans[i])
               continue;
                for(long long j=i*i;j<n;j+=i)
                   ans[j]=false;
        }

        int cnt=0;
        for(int i=2;i<n;i++){
            if(ans[i])
               cnt++;
        }
        return cnt;
    }
};


// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0