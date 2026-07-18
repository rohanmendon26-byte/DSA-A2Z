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



//OPTIMAL APPROACH (MATHEMATICS METHOD)
// Time Complexity
// O(n)
// Space Complexity
// O(1)

#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long N=arr.size();
	//S - Sn = x - y
	//S2 - S2N
	long long SN=(n*(n+1))/2;
	long long S2N=(n*(n+1)*(2*n+1))/6;
	long long S=0,S2=0;
	for(int i=0;i<n;i++){
		S+=arr[i];
		S2+= (long long)arr[i] * (long long)arr[i];
	}
	long long val1 = S-SN;
	long long val2 = S2-S2N;
	val2=val2/val1;
	long long x =(val1+val2)/2;
	long long y = x-val1;
	return {(int)y,(int)x};
	
}



