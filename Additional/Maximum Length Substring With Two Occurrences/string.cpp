class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(26,0);
        int left=0,ans=0;
        for(int right=0;right<s.size();right++){
            freq[s[right]-'a']++;

            while(freq[s[right]-'a']>2){
                freq[s[left]-'a']--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};



// Input: s = "bcbbbcba"
// Output: 4
// Explanation:
// The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".


// Input: s = "aaaa"
// Output: 2
// Explanation:
// The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".