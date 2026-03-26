//rotate an array once
class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int temp=arr[arr.size()-1];
        for(int i=arr.size()-1;i>=0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=temp;
    }
};

//input[1,2,3,4,5]
//output[5,1,2,3,4]


//rotate an array by k places(Brute force method)
vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    k = k % n;

    vector<int> temp(k);

    // store first k elements
    for(int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }

    // shift remaining elements
    for(int i = k; i < n; i++) {
        arr[i - k] = arr[i];
    }

    // put temp elements at end
    for(int i = n - k; i < n; i++) {
        arr[i] = temp[i - (n - k)];
    }

    return arr;
}


//rotate the array by k places to left(optimal method)
class Solution {
public:

    void reverse(int start,int end,vector<int>& nums){
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        if(k<0){
            k=k+nums.size();
        }

        reverse(0,k-1,nums);
        reverse(k,nums.size()-1,nums);
        reverse(0,nums.size()-1,nums);

    }
};


//move zeros to the end of the array (BRUTE FORCE)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
              temp.push_back(nums[i]);
        }

        for(int i=0;i<temp.size();i++){
            nums[i]=temp[i];
        }

        for(int i=temp.size();i<n;i++){
            nums[i]=0;
        }
    }
};


//move zeros to the end of the array (OPTIMAL)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int j=-1;
       int n=nums.size();
       for(int i=0;i<n;i++){
        if(nums[i]==0){
            j=i;
            break;
        }
       
    }

    for(int i=j+1;i<n;i++){
        if(nums[i]!=0){
            swap(nums[i],nums[j])
            j++;
        }
    }
};