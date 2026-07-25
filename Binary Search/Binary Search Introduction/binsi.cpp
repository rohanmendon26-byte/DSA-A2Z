// Hence, the time complexity is:

// Best Case: O(1) (target is found at the first middle element)
// Average Case: O(log n)
// Worst Case: O(log n)

// Binary search
int search(vector<int> &nums, int target)
{
    int n = nums.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        else if (nums[mid] < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }
    return -1;
}


// Recursive Method
class Solution
{
public:
    int bs(vector<int> &nums, int low, int high, int target)
    {
        if (low > high)
        {
            return -1;
        }
        int mid = (low + high) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            return bs(nums, mid + 1, high, target);
        }
        return bs(nums, low, mid - 1, target);
    }
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        return bs(nums, 0, n - 1, target);
    }
};



//First Occurrence in Sorted (Other problem)
// Complexity
// Time: O(log n)
// Space: O(1)

class Solution {
  public:
    int firstSearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k){
                ans=mid;
                high=mid-1;
            }
            
            else if(arr[mid]<k){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }
};


// Input: arr[] = [1, 2, 3, 4, 5], k = 4
// Output: 3
// Explanation: 4 appears at index 3.

// Input: arr[] = [11, 22, 33, 44, 55], k = 445
// Output: -1
// Explanation: 445 is not present.

// Input: arr[] = [1, 1, 1, 1, 2], k = 1
// Output: 0
// Explanation: 1 appears at index 0.