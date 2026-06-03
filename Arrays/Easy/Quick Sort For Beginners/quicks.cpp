#include <bits/stdc++.h> 
using namespace std;  

//Time complexity--> O(nlog n)
//Space complexity--> O(1)

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }

        while(arr[j] > pivot && j >= low + 1){
            j--;
        }

        if(i < j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);

        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> arr){
    qs(arr, 0, arr.size() - 1);
    return arr;
}

int main(){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> sorted = quickSort(arr);

    cout << "Sorted array:\n";
    for(int x : sorted){
        cout << x << " ";
    }

    return 0;
}