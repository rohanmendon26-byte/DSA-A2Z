// Time Complexity
// Merge Sort: O(nlogn)
// Space Complexity: O(n)

#include <bits/stdc++.h> 
long long cnt=0;
void merge(vector<long long> &arr, int low, int mid, int high)
{
    vector<long long> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt+=(mid-left+1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergesort(vector<long long> &arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<long long>v(arr,arr+n);
    cnt=0;
    mergesort(v,0,n-1);
    return cnt;
}


// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

// Input: arr[] = [2, 3, 4, 5, 6]
// Output: 0
// Explanation: As the sequence is already sorted so there is no inversion count.

// Input: arr[] = [10, 10, 10]
// Output: 0
// Explanation: As all the elements of array are same, so there is no inversion count.