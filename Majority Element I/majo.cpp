//Best Case
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	map<int,int>mpp;
	for(int i=0;i<n;i++){
		mpp[arr[i]]++;
	}

	for(auto it:mpp){
		if(it.second > (n/2)){
			return it.first;
		}
	}
	return -1;
}



//optimal approach
//Time Complexity--> O(N)
//Space Complexity--> O(1)
#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// Write your code here.
	int cnt=0;
	int el;
	for(int i=0;i<n;i++){
		if(cnt==0){
			cnt=1;
			el=arr[i];
		}

		else if(arr[i]==el){
			cnt++;
		}
		
		else{
			cnt--;
		}
	}

	int cnt1=0;
	for(int i=0;i<n;i++){
		if(arr[i]==el)
		  cnt1++;
	}

	if(cnt1 > (n/2)){
		return el;
	}
	return -1;
}