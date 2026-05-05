//Longest Subarray (Brute force)
int length = 0;
for(int i = 0; i < n; i++) {
    int s = 0;
    for(int j = i; j < n; j++) {
        s += a[j];

        if(s == k) {
            length = max(length, j - i + 1);
        }
    }
}

cout << length; //-->Time complexity (O(n**2))

// a = [1, 2, 3, 1, 1, 1, 1]
// k = 3
// 3



#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    map<long long,int> presummap;
    long long sum=0;
    int maxlen=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i];

        if(sum==k){
            maxlen=max(maxlen,i+1);
        }
        long long rem=sum-k;
        if(presummap.find(rem)!=presummap.end()){
            int len=i-presummap[rem];
            maxlen=max(maxlen,len);
        }
        if(presummap.find(sum)==presummap.end()){
            presummap[sum]=i;
        }
    }
    return maxlen;
}

// a = [1, 2, 3, 1, 1, 1, 1]
// k = 3
// 3


//Longest Subarray (Optimal approach)

#include <bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left=0,right=0;
    long long sum=a[0];
    int n=a.size();
    int maxlen=0;
    while(right<n){
        while(left<=right && sum>k){
            sum=sum-a[left];
            left++;
        }
        if(sum==k){
           maxlen=max(maxlen,right-left+1);
        }

        right++;
        if(right<n){
            sum=sum+a[right];
        }
    }
    return maxlen;   
}

// a = [1, 2, 1, 1, 1, 3]
// k = 3
// 3