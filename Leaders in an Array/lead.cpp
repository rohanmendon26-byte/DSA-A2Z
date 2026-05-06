#include <bits/stdc++.h> 
vector<int> findLeaders(vector<int> &elements, int n) {
    // Write your code here.
    vector<int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(elements[i]>maxi){
            ans.push_back(elements[i]);
        }
        maxi=max(maxi,elements[i]);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

// Input: arr = [16, 17, 4, 3, 5, 2]
// Output: [17, 5, 2]
// Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.