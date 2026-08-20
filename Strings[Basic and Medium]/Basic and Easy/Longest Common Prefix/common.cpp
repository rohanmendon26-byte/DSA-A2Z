// // Time Complexity: O(N * log N + M), where N is the number of strings and M is the minimum length of a string. The sorting operation takes O(N * log N) time, and the comparison of characters in the first and last strings takes O(M) time.

// // Space Complexity: O(M), as the ans variable can store the length of the prefix which in the worst case will be O(M).


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
           return "";

        sort(strs.begin(),strs.end());

        string first=strs[0];
        string last=strs[strs.size()-1];

        int minlength=min(first.size(),last.size());

        string ans="";

        for(int i=0;i<minlength;i++){
            if(first[i]!=last[i])
              break;
            ans+=first[i];
        }

        return ans;
    }
};

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.