
// Time: O(N log S)
// Space: O(1)



class Solution
{
public:
    int func(vector<int> &weights, int cap)
    {
        int days = 1, load = 0;
        for (int i = 0; i < weights.size(); i++)
        {
            if (weights[i] + load > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int noofdays = func(weights, mid);
            if (noofdays <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};



// Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
// Output: 15
// Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
// 1st day: 1, 2, 3, 4, 5
// 2nd day: 6, 7
// 3rd day: 8
// 4th day: 9
// 5th day: 10

// Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.

// Input: weights = [3,2,2,4,1,4], days = 3
// Output: 6
// Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
// 1st day: 3, 2
// 2nd day: 2, 4
// 3rd day: 1, 4


// Input: weights = [1,2,3,1,1], days = 4
// Output: 3
// Explanation:
// 1st day: 1
// 2nd day: 2
// 3rd day: 3
// 4th day: 1, 1


// Input: arr[] = [1, 2, 1], d = 2
// Output: 3
// Explanation: We can ship with boat capacity 3 in 2 days.
// Day 1- 1,2
// Day 2- 1


// Input: arr[] = [9, 8, 10], d = 3
// Output: 10
// Explanation: We can ship with boat capacity 10 in 3 days.
// Day 1- 9
// Day 2- 8
// Day 3- 10