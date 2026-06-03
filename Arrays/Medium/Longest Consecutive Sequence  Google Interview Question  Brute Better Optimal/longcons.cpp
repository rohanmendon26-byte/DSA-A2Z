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

// input: 33 20 34 30 35
// output : 3


//optimal solution
// Time Complexity--> o(n)

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    int longest=1;
    int count=0;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it:st){
        if(st.find(it-1)==st.end()){
            count=1;
           int x=it;
            while(st.find(x+1)!=st.end()){
                count+=1;
                x=x+1;
            }
            longest=max(longest,count);
        }
    }
    return longest;
}