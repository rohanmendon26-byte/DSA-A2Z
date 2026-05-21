//Better solution

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int longest=1;
    int count=0;
    int lastnumber=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]-1 == lastnumber){
            count+=1;
            lastnumber=arr[i];
        }

        else if(lastnumber!=arr[i]){
            count=1;
            lastnumber=arr[i];
        }
        longest=max(longest,count);
    }

    return longest;
}