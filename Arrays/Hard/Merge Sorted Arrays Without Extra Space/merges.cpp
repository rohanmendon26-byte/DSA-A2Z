// Time Complexity: O(m + n)
// Space Complexity: O(1)
//This code is only for leetcode (THREE-POINTER-APPROACH)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        while(i>=0 && j>=0){
            if(nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }

        while(j>=0){
            nums1[k--]=nums2[j--];
        }
    }
};

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.










// Time Complexity: O((n + m) log(n + m))
// Space Complexity: O(1)
//For GFG and CODING NINJAS

class Solution {

    void swapIfGreater(vector<int>& a, vector<int>& b, int i, int j) {
        if (a[i] > b[j])
            swap(a[i], b[j]);
    }

public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int len = m + n;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {

            int left = 0;
            int right = left + gap;

            while (right < len) {

                // nums1 & nums2
                if (left < m && right >= m) {
                    swapIfGreater(nums1, nums2, left, right - m);
                }

                // nums2 & nums2
                else if (left >= m) {
                    swapIfGreater(nums2, nums2, left - m, right - m);
                }

                // nums1 & nums1
                else {
                    swapIfGreater(nums1, nums1, left, right);
                }

                left++;
                right++;
            }

            if (gap == 1)
                break;

            gap = (gap / 2) + (gap % 2);
        }

        for (int i = m; i < m + n; i++)
            nums1[i] = nums2[i - m];
    }
};

// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
// Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]


// Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
// Output: a[] = [1, 2, 3, 5, 8, 9], b[] = [10, 13, 15, 20]
// Explanation: After merging two sorted arrays we get [1, 2, 3, 5, 8, 9, 10, 13, 15, 20].

// Input: a[] = [0, 1], b[] = [2, 3]
// Output: a[] = [0, 1], b[] = [2, 3]
// Explanation: After merging two sorted arrays we get [0, 1, 2, 3].