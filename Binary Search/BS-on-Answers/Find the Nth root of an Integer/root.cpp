// Time  : O(n log m)
// Space : O(1)



class Solution {
public:

    int func(int mid, int n, int m) {
        long long ans = 1;

        for(int i = 0; i < n; i++) {
            ans = ans * mid;

            if(ans > m)
                return 2;
        }

        if(ans == m)
            return 1;
        else
            return 0;
    }

    int nthRoot(int n, int m) {
        int low = 1, high = m;
        
        if(m==0)
           return 0;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int midn = func(mid, n, m);

            if(midn == 1)
                return mid;

            else if(midn == 0)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return -1;
    }
};


// Input: n = 3, m = 8
// Output: 2
// Explanation: 2^3 = 8

// Input: n = 3, m = 9
// Output: -1
// Explanation: 3rd root of 9 is not integer.

// Input: n = 4, m = 16
// Output: 2
// Explanation: 2^4 = 16