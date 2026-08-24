// Time Complexity: O(n), where n is the length of the string.

// Space Complexity: O(1), as only constant extra space is used.

class Solution {
public:
    int maxDepth(string s) {
        int counter=0;
        int maxdepth=0;

        for(char ch:s){
            if(ch=='(')
               counter++;
            else if(ch==')')
               counter--;
            
            maxdepth=max(maxdepth,counter);
        }

        return maxdepth;
    }
};



// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation:
// Digit 8 is inside of 3 nested parentheses in the string.



// Input: s = "(1)+((2))+(((3)))"
// Output: 3
// Explanation:
// Digit 3 is inside of 3 nested parentheses in the string.



// Input: s = "()(())((()()))"
// Output: 3