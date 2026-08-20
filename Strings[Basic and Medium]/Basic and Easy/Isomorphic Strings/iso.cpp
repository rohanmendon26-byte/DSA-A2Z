// Time Complexity: O(N) where N is the length of the input strings, due to the single loop iterating through each character.

// Space Complexity: O(1) since the space used by the arrays is constant (256 fixed size) regardless of input size


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m1[256]={0},m2[256]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            if(m1[s[i]]!=m2[t[i]])
               return false;
            
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }

        return true;
    }
};


// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"

// Output: false

// Explanation:

// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true