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
 