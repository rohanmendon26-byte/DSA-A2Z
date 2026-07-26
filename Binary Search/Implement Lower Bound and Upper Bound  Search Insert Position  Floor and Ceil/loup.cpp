// Time Complexity
// O(log n) because it uses binary search.
// Space Complexity
// O(1) (constant extra space)
// Lower Bound
class Solution
{
public:
    int lowerBound(vector<int> &arr, int target)
    {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
// Output: 4
// Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
// Output: 7
// Explanation: As no element in arr[] is greater than 100, return the length of array.

// Example 1: Get the value
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 4, 4, 5};

    auto it = lower_bound(arr.begin(), arr.end(), 4);

    if (it != arr.end())
        cout << *it; // Output: 4
}

// Example 2: Get the index
vector<int> arr = {1, 2, 4, 4, 5};

int index = lower_bound(arr.begin(), arr.end(), 4) - arr.begin();

cout << index; // Output: 2



//Upper bound
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
// Output: 3
// Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.

// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
// Output: 6
// Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.

// Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
// Output: 7
// Explanation: As no element in arr[] is greater than 100, return the length of array.



// Search Insert Position (It is same as lower bound)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
           int mid=low+(high-low)/2;

            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4


// Time Complexity
// floor() → O(log n)
// ceil() → O(log n)
//Floor and ceil
int floor(vector<int>arr,int x){
	int n=arr.size();
	int low=0,high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;

		if(arr[mid]<=x){
			ans=arr[mid];
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	return ans;
}

int ceil(vector<int>arr,int x){
	int n=arr.size();
	int low=0,high=n-1;
	int ans=-1;
	while(low<=high){
		int mid=low+(high-low)/2;

		if(arr[mid]>=x){
			ans=arr[mid];
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int b=floor(a,x);
	int y=ceil(a,x);
	return{b,y};
	
}
 