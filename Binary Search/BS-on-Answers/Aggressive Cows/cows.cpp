
// Overall:
// O(nlogn+nlog(maxDistance))
// Space Complexity
// O(1)




class Solution
{
public:
    bool can_place(vector<int> &arr, int dist, int k)
    {
        int cntcows = 1, last = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - last >= dist)
            {
                cntcows += 1;
                last = arr[i];
            }
            if (cntcows >= k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &arr, int k)
    {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int low = 1, high = arr[n - 1] - arr[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (can_place(arr, mid, k) == true)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};



// Input: arr[] = [1, 2, 4, 8, 9], k = 3
// Output: 3
// Explanation: The first cow can be placed at arr[0], the second at arr[2], and the third at arr[3]. The minimum distance between any two cows is 3 (between arr[0] and arr[2]), which is the maximum possible among all valid arrangements.

// Input: arr[] = [10, 1, 2, 7, 5], k = 3
// Output: 4
// Explanation: The first cow can be placed at arr[0], the second at arr[1], and the third at arr[4]. In this arrangement, the minimum distance between any two cows is 4 (between arr[1] and arr[4]), which is the maximum possible among all valid arrangements.