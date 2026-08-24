// Time Complexity: O(n), where n is the length of the input string since we traverse the string once.
// Space Complexity: O(1), since we use a fixed-size map for Roman numerals.


class Solution {
public:
    int romanToInt(string s) {
        int res=0;

        unordered_map<char,int>roman={
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},
            {'D',500},{'M',1000}
        };

        for(int i=0;i<s.size()-1;i++){
            if(roman[s[i]]<roman[s[i+1]])
               res=res-roman[s[i]];
            else
               res=res+roman[s[i]];
        }

        return res+roman[s.back()];
    }
};


// Input: s = "III"
// Output: 3
// Explanation: III = 3.


// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.


// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.