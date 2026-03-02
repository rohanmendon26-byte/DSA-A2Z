#include<iostream>
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
    int hash[13]={0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;
    }
    
    cout<<"Enter the query";
    int q;
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number to find it's frequency";
        cin>>number;
        //fetch
        cout<<hash[number]<<endl;
    }
    return 0;
}