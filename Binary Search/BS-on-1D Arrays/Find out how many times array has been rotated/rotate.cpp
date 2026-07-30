// Time Complexity
// O(log n)
// Space Complexity
// O(1)

#include <bits/stdc++.h>
int findKRotation(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < ans)
            {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }

        else
        {
            if (arr[mid] < ans)
            {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}

//  if (arr[low] < ans)
//  {
//      index = low;      ---->   ans=min(ans,arr[low]);
//      ans = arr[low];
//  }



// Input: arr[] = [5, 1, 2, 3, 4]
// Output: 1
// Explanation: The given array is [5, 1, 2, 3, 4]. The original sorted array is [1, 2, 3, 4, 5]. We can see that the array was rotated 1 times to the right.

// Input: arr = [1, 2, 3, 4, 5]
// Output: 0
// Explanation: The given array is not rotated.




// Even Simpler (Striver's Approach)
// class Solution {
// public:
//     int findKRotation(vector<int> &arr) {
//         int low = 0, high = arr.size() - 1;

//         while (low < high) {
//             int mid = low + (high - low) / 2;

//             if (arr[mid] > arr[high])
//                 low = mid + 1;
//             else
//                 high = mid;
//         }

//         return low;
//     }
// };