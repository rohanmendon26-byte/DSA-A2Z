// Complexity

// Each search is binary search, so:

// firstSearch() → O(log n)
// lastSearch() → O(log n)

// Total:
// Time: O(log n)
// Space: O(1)


//COUNT THE NUMBER OF OCCURENCES
int firstSearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k){
                ans=mid;
                high=mid-1;
            }
            
            else if(arr[mid]<k){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }


  int lastSearch(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int ans=-1;
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(arr[mid]==k){
                ans=mid;
                low=mid+1;
            }
            
            else if(arr[mid]<k){
                low=mid+1;
            }
            
            else{
                high=mid-1;
            }
        }
        
        return ans;
    }

pair<int,int> firstandLast(vector<int>&arr,int k){
    int first=firstSearch(arr,k);
    if(first==-1)
      return{-1,-1};
    int last=lastSearch(arr,k);
    return{first,last};
}

int count(vector<int>& arr, int n, int x) {
	pair<int,int>ans=firstandLast(arr,x);
    if(ans.first==-1)
       return 0;
    return ans.second-ans.first+1;

}



// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
// Output: 4
// Explanation: target = 2 occurs 4 times in the given array so the output is 4.

// Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
// Output: 0
// Explanation: target = 4 is not present in the given array so the output is 0.

// Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
// Output: 3
// Explanation: target = 12 occurs 3 times in the given array so the output is 3.
