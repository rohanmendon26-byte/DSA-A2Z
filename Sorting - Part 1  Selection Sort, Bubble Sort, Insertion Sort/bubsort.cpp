#include<iostream>
using namespace std;

//time complexity -> O(n**2) --> for worst-case & average-case
//time complexity -> O(n)--> for best-case after optimization(if the array is already in the sorted order)

void bubblesort(int arr[],int n){
    for(int i=n-1;i>=1;i--){
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1])
               swap(arr[j+1],arr[j]);
        }
        //temp=arr[min];
        //arr[min]=arr[i];
        //arr[i]=temp;
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
    bubblesort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}