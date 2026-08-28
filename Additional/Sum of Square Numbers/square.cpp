// Time: O(√c)
// Space: O(1)


class Solution {
public:
    bool judgeSquareSum(int c) {
        long long square=sqrt(c);

        for(int i=0;i<=square;i++){
            int remaining=c-(i*i);
            int j=sqrt(remaining);
            if(j*j==remaining)
               return true;
        }
        return false;
    }
};

// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:

// Input: c = 3
// Output: false


//two pointer approach
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while (left <= right) {
            long long sum = left * left + right * right;

            if (sum == c) {
                return true;
            }
            else if (sum < c) {
                left++;
            }
            else {
                right--;
            }
        }

        return false;
    }
};