class Solution {
     vector<int> generaterow(int row){
        long long ans=1;
        vector<int>ansrow;
        ansrow.push_back(ans);
        for(int col=1;col<row;col++){
            ans=ans*(row-col);
            ans=ans/col;
            ansrow.push_back(ans);
        }
        return ansrow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
         for(int i=1;i<=numRows;i++){
           ans.push_back(generaterow(i));
       }
       return ans;
    }
};

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
// Example 2:

// Input: numRows = 1
// Output: [[1]]




#include <bits/stdc++.h> 
vector<long long int> kthRow(int k) 
{
	long long ans=1;
	vector<long long int>ansrow;
	ansrow.push_back(ans);

	for(int col=1;col<k;col++){
		ans=ans*(k-col);
		ans=ans/col;
		ansrow.push_back(ans);
	}
	return ansrow;
} 


// Example :-

// INPUT : K = 2
// OUTPUT: 1 1

// INPUT   : K = 4
// OUTPUT  : 1 4 6 4 1
 