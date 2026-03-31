//Longest Subarray (Brute force)
for(i=0;i<n;i++){
    s=0;
    for(j=i;j<n;j++){
        s+=a[j];

        if(s==k)
           length=max(length,j-i+1)
    }
}
print(len)  //-->Time complexity (O(n**2))



//Longest Subarray (Better approach)
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
        int rem=sum-k;
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