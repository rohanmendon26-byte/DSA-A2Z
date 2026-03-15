#include <bits/stdc++.h>
//Largest element in an array

int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest)
           largest=arr[i];
    }
    return largest;
}



class Solution {
  public:
  //Second largest element in array
    int getSecondLargest(vector<int> &arr) {
        // code here
        int largest=arr[0];
        int slargest=-1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }
            
            else if(arr[i]<largest && arr[i]>slargest){
                slargest=arr[i];
            }
        }
        return slargest;
    }
};



//check if the array is sorted
class Solution {
public:
    bool check(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){

            }
            else{
                return false;
            }
        }
        return true;
    }
};



//check if the array is sorted and rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                count++;
            }
        }
        return count<=1;
    }
};


//Remove duplicates from sorted arrays
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i=0;
	for(int j=1;j<n;j++){
		if(arr[j]!=arr[i]){
			arr[i+1]=arr[j];
			i++;
		}
	}
	return i+1;
}

