// For interview purposes, I would say Time: O(N + K log K), Space: O(N).


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;

        for(char ch:s){
            freq[ch]++;
        }

        vector<pair<int,char>>v;

        for(auto it:freq){
            v.push_back({it.second,it.first});
        }

        sort(v.rbegin(),v.rend());

        string ans="";
        for(auto it:v){
            ans.append(it.first,it.second);
        }
        return ans;
    }
};



// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.


// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.