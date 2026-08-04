// Time complexity: O(n log(max(nums)))
// Space complexity: O(1) apart from the input array.

class Solution
{
public:
    int sumofd(vector<int> &arr, int div)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += ceil((double)arr[i] / (double)div);
        }
        return sum;
    }

    int smallestDivisor(vector<int> &nums, int threshold)
    {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (sumofd(nums, mid) <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};



// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 

// Input: nums = [44,22,33,11,1], threshold = 5
// Output: 44


// Input: arr[] = [1, 2, 5, 9], k = 6
// Output: 5
// Explanation: 5 is the smallest divisor having sum of quotients (1 + 1 + 1 + 2 = 5) less than or equal to 6.

// Input: arr[] = [1, 1, 1, 1], k = 4
// Output: 1
// Explanation: 1 is the smallest divisor having sum of quotients (1 + 1 + 1 + 1 = 4) less than or equal to 4.