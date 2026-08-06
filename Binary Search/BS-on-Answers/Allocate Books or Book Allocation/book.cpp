// Overall:
// O(nlogS)
// 	​
// Space:
// O(1)
	​

int func(vector<int> &arr, int n, int mid)
{
    int student = 1, pagestudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagestudent + arr[i] <= mid)
            pagestudent += arr[i];
        else
        {
            student += 1;
            pagestudent = arr[i];
        }
    }
    return student;
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    if (n < m)
        return -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int students = func(arr, n, mid);
        if (students > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}



// Input: arr[] = [12, 34, 67, 90], k = 2
// Output: 113
// Explanation: Allocation can be done in following ways:
// => [12] and [34, 67, 90] Maximum Pages = 191
// => [12, 34] and [67, 90] Maximum Pages = 157
// => [12, 34, 67] and [90] Maximum Pages = 113.
// The third combination has the minimum pages assigned to a student which is 113.



// Input: arr[] = [15, 17, 20], k = 5
// Output: -1
// Explanation: Since there are more students than total books, it's impossible to allocate a book to each student.