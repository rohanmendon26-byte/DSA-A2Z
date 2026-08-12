// Time: O(n1 + n2)
// Space: O(n1 + n2)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> temp;
        int i = 0, j = 0;
        while (i < n1 &&  j < n2) {
            if (nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else {
                temp.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n1) {
            temp.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            temp.push_back(nums2[j]);
            j++;
        }

        int n=n1+n2;
        if(n%2==1)
          return temp[n/2];

        return (temp[n / 2] + temp[n / 2 - 1]) / 2.0;
    }
};



//Better approach
// Your current algorithm is:
// Time: O(n1 + n2)
// Space: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
    
        int i = 0, j = 0;
        int n=n1+n2;
        int ind2=n/2;
        int ind1=ind2-1;
        int cnt=0;
        int ind1el=-1,ind2el=-1;

        while (i < n1 &&  j < n2) {
            if(nums1[i]<nums2[j]){
                if(cnt==ind1)
                   ind1el=nums1[i];
                if(cnt==ind2)
                   ind2el=nums1[i];
                cnt++;
                i++;
            }

            else{
               if(cnt==ind1)
                   ind1el=nums2[j];
                if(cnt==ind2)
                   ind2el=nums2[j];
                cnt++;
                j++; 
            }
        }

        while (i < n1) {
             if(cnt==ind1)
                   ind1el=nums1[i];
                if(cnt==ind2)
                   ind2el=nums1[i];
                cnt++;
                i++;
        }

        while(j<n2){
            if(cnt==ind1)
                   ind1el=nums2[j];
                if(cnt==ind2)
                   ind2el=nums2[j];
                cnt++;
                j++;
        }

        
        if(n%2==1)
          return ind2el;

        return (ind1el+ind2el)/2.0;
    }
};

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.




///optimal approach
// Time Complexity
// O(log(min(n1, n2)))

class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        // code here
        int n1=a.size();
        int n2=b.size();
        if(n1>n2)
           return medianOf2(b,a);
        int low=0,high=n1;
        int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1)
              r1=a[mid1];
            if(mid2<n2)
              r2=b[mid2];
            if(mid1-1 >=0)
               l1=a[mid1-1];
            if(mid2-1>=0)
               l2=b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1)
                  return max(l1,l2);
                return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
            }
            else if(l1>l2)
                high=mid1-1;
            else
                low=mid1+1;
        }
        return 0;
    }
};
 

// Input: a[] = [3, 5, 6, 12, 15], b[] = [3, 4, 6, 10, 10, 12]
// Output: 6
// Explanation: The merged array is [3, 3, 4, 5, 6, 6, 10, 10, 12, 12, 15]. So the median of the merged array is 6.

// Input: a[] = [2, 3, 5, 8], b[] = [10, 12, 14, 16, 18, 20]
// Output: 11
// Explanation: The merged array is [2, 3, 5, 8, 10, 12, 14, 16, 18, 20]. So the median of the merged array is (10 + 12) / 2 = 11.

// Input: a[] = [], b[] = [2, 4, 5, 6]
// Output: 4.5
// Explanation: The merged array is [2, 4, 5, 6]. So the median of the merged array is (4 + 5) / 2 = 4.5.