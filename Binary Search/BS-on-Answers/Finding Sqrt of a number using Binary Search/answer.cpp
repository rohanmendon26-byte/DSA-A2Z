// Time: O(log n)
// Space: O(1)

int floorSqrt(int n)
{
    int low=1,high=n;
    while(low<=high){
        long long mid=low+(high-low)/2;

        if(mid*mid<=n){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return high;
}


// Input: n = 4
// Output: 2
// Explanation: Since, 4 is a perfect square, so its square root is 2.

// Input: n = 11
// Output: 3
// Explanation: Since, 11 is not a perfect square, floor of square root of 11 is 3.

// Input: n = 1
// Output: 1
// Explanation: 1 is a perfect sqaure, so its square root is 1.