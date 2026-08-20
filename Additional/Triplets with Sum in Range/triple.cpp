// Time Complexity: O(n²)
// Space Complexity: O(1) extra space



class Solution {
	public:
	int countlessequal(vector<int> &arr, int x) {
		// code here
		int count = 0;
		sort(arr.begin(),arr.end());
		for (int i = 0; i<arr.size(); i++) {
			int j = i + 1;
			int k = arr.size() - 1;
			
			while (j<k) {
				int sum = arr[i]+arr[j]+arr[k];
				
				if (sum <= x) {
					count += (k - j);
					j++;
				}
				else {
					k--;
				}
			}
		}
		
		return count;
	}
	
	int countTriplets(vector<int> &arr, int l, int r) {
		// code here
		return countlessequal(arr, r) - countlessequal(arr, l - 1);
	}
};


// Input: arr = [8, 3, 5, 2], l = 7, r = 11
// Output: 1
// Explanation: There is only one triplet [2, 3, 5] having sum 10 in range [7, 11].

// Input: arr = [5, 1, 4, 3, 2], l = 2, r = 7
// Output: 2
// Explanation: There are two triplets having sum in range, [1,4,2] and [1,3,2].