// Time: O(n log m)
// Space: O(1)


int lower_bound(vector<int>&arr,int n,int x){
    int low=0,high=n-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x)
          high=mid-1;
        else
          low=mid+1;
    }
    return low;
}



int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max=0;
    int index=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m-lower_bound(matrix[i],m,1);
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            index=i;
        }
    }
    return index;
}


// Input: arr[][] = [[0,1,1,1],
//                [0,0,1,1],
//                [1,1,1,1],
//                [0,0,0,0]]
// Output: 2
// Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

// Input: arr[][] = [[0,0],
//                [1,1]]
// Output: 1
// Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

// Input: arr[][] = [[0,0], 
//                [0,0]]
// Output: -1
// Explanation: No row contains any 1s, so the output is -1.




//Minimum number of 1s
class Solution {
	public:
	int lower_bound(vector<int>&arr, int n, int x) {
		int low = 0, high = n - 1;
		while (low <= high) {
			int mid = low + (high - low)/2;
			if (arr[mid] >= x)
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
	}
	
	int minRow(vector<vector<int>> &mat) {
		int n=mat.size();
		int m=mat[0].size();
		int cnt_min=m+1;
		int index=-1;
		for(int i=0;i<n;i++){
		    int cnt_ones=m-lower_bound(mat[i],m,1);
		    if(cnt_ones<cnt_min){
		        cnt_min=cnt_ones;
		        index=i;
		    }
		}
		return index;
		
	}
};


//minimum number of 1s which is not sorted
// Complexity: O(n × m) time, O(1) space.
class Solution {
public:
    int minRow(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int minOnes = m + 1;
        int ans = 1;

        for (int i = 0; i < n; i++) {
            int count = 0;

            for (int j = 0; j < m; j++) {
                count += mat[i][j];
            }

            if (count < minOnes) {
                minOnes = count;
                ans = i + 1;
            }
        }

        return ans;
    }
};

// Input: mat = [[1, 1, 1, 1], [1, 1, 0, 0], [0, 0, 1, 1], [1, 1, 1, 1]]
// Output: 2
// Explanation: Rows 2 and 3 contain the minimum number of 1's (2 each). Since, row 2 is less than row 3. Thus, the answer is 2.

// Input: mat = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
// Output: 1
// Explanation: All the rows contain the same number of 1's (0 each). Among them, index 1 is the smallest, so the answer is 1.
