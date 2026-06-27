//Brute force O(n³)
#include<bits/stdc++.h>
vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k]==0){
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// input: ‘N’ = 5 
// 'ARR' =  [-1, -1, 2, 0, 1] 

// Output: 
// -1 -1 2
// -1 0 1
