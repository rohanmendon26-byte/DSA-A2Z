#include<iostream>
using namespace std;

//time complexity -> O(n**2)

void selectionsort(int arr[],int n){
    for(int i=0;i<=n-2;i++){
        int min=i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min])
               min=j;
        }
        swap(arr[min],arr[i]);
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
    selectionsort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}