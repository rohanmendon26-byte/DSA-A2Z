// Time Complexity: O(N), where N is the length of the strings. Each string is traversed once, and the frequency array is checked in constant time (26 iterations).

// Space Complexity: O(1), as a fixed-size array of 26 elements is used regardless of the input size.


class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
           return false;

        int freq[26]={0};

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }

        for(int i=0;i<t.size();i++){
            freq[t[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
               return false;
        }

        return true;
    }
};


// Input: s = "anagram", t = "nagaram"
// Output: true


// Input: s = "rat", t = "car"
// Output: false