// Time Complexity
// Creating the hash array: O(n)
// Traversing the hash array: O(n)

//BETTER SOLUTION

#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int hash[n+1]={0};
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	int repeated=-1,missing=-1;
	for(int i=1;i<=n;i++){
		if(hash[i]==2)
		   repeated=i;
		else if(hash[i]==0)
		   missing=i;
	    if(repeated!=-1 && missing!=-1)
		   break;
	}
	return{missing,repeated};
	
}

// Input: arr[] = [2, 2]
// Output: [2, 1]
// Explanation: Repeating number is 2 and the missing number is 1.

// Input: arr[] = [1, 3, 3] 
// Output: [3, 2]
// Explanation: Repeating number is 3 and the missing number is 2.

// Input: arr[] = [4, 3, 6, 2, 1, 1]
// Output: [1, 5]
// Explanation: Repeating number is 1 and the missing number is 5.


