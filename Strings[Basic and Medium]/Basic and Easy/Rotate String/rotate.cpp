// Time Complexity: O(N), because checking for a substring in s + s is linear in time.

// Space Complexity: O(N) for the space needed to store the concatenated string s + s.


class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())
           return false;
        
        string doubleS=s+s;
        return doubleS.find(goal)!=string::npos;
    }
};

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false