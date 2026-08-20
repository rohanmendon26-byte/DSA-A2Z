// Time Complexity: O(N), We traverse the string once from right to left and construct the result directly without extra passes.

// Space Complexity: O(1),Ignoring the output string, no additional data structures proportional to input size are used.

class Solution {
public:
    string reverseWords(string s) {
        string result="";
        int i=s.size()-1;

        while(i>=0){
            while(i>=0 && s[i]==' ')
                i--;

            if(i<0)
               break;

            int end=i;
            
            while(i>=0 && s[i]!=' ')
               i--;

            if(!result.empty())
               result+=" ";
            
            string word=s.substr(i+1,end-i);

            result+=word;
        }
        return result;
    }
};



// Example 1:
// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.