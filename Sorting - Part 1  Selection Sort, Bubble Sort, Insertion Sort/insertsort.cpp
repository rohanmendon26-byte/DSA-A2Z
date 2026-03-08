#include<iostream>
using namespace std;

//time complexity -> O(n**2)

void insertsort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
}


int main()
{
    int n,i;
    cout<<"Enter the size of the array:";
    cin>>n;
    int arr[n];
    cout<<"Enter the array:";
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    insertsort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}