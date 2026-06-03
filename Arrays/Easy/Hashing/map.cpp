#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of the array";
    cin>>n;
    int arr[n];
    cout<<"Enter the array numbers";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute
    map<int, int>mpp;
    // unordered_map<int, int>mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    for(auto it:mpp){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    
    cout<<"Enter the query";
    int q;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number to find it's frequency";
        cin>>number;
        //fetch
        cout<<mpp[number]<<endl;
    }
    return 0;
}