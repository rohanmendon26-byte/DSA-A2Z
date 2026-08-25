// Time: O(n²)
// Space: O(1) excluding the returned string.

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
          return s;

        int start=0;
        int maxlen=1;

        for(int i=0;i<s.size();i++){
            //odd length

            int left=i;
            int right=i;

            while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1 > maxlen){
                    start=left;
                    maxlen=right-left+1;
                }

                left--;
                right++;
            }

            //even length
            left=i;
            right=i+1;

              while(left>=0 && right<s.size() && s[left]==s[right]){
                if(right-left+1 > maxlen){
                    start=left;
                    maxlen=right-left+1;
                }

                left--;
                right++;
            }


        }

        return s.substr(start,maxlen);
    }
};




// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Input: s = "cbbd"
// Output: "bb"

// Input: s = "forgeeksskeegfor"
// Output: geeksskeeg
// Explanation: There are several possible palindromic substrings like "kssk", "ss", "eeksskee" etc. But the substring "geeksskeeg" is the longest among all.

// Input: s = "abacac"
// Output: aba
// Explanation: The palindromic substrings "aba", "aca" and "cac" all have the same length. Since "aba" appears first, it is the answer.

// Input: s = "geeks"
// Output: ee
// Explanation: The longest palindromic substring present in the given string is "ee".