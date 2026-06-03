//Reverse an array
#include<iostream>
using namespace std;

void f(int i,int arr[],int n){
    if(i>=n/2)
       return;
    swap(arr[i],arr[n-i-1]);
    f(i+1,arr,n);
}

int main()
{
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       cin>>arr[i];
    f(0,arr,n);
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";

    return 0;
}