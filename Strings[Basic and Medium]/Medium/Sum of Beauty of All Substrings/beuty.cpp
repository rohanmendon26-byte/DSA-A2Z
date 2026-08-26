// Time Complexity:
// Outer loop: O(n) (for each starting index)
// Inner loop: O(n) (for each ending index)
// Computing max and min for frequencies: O(26) in the worst case (since only lowercase letters), O(n^2 * 26) ≈ O(n^2) because 26 is constant.

// Space Complexity:
// Frequency map uses at most 26 characters → O(26) = O(1).
// No extra data structures apart from that.


class Solution {
public:
    int beautySum(string s) {
        int sum=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>freq;

            for(int j=i;j<s.size();j++){
                freq[s[j]]++;

                int mini=INT_MAX;
                int maxi=INT_MIN;

                for(auto it:freq){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }

                sum+=(maxi-mini);
            }
        } 
        return sum;  
    }
};



// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

// Input: s = "aabcbaa"
// Output: 17




//optimal approach
int sumOfBeauty(string s) {
	int n=s.size();
	int sum=0;

	for(int i=0;i<n;i++){
		int freq[26]={0};
		int maxi=0;

		for(int j=i;j<n;j++){
			freq[s[j]-'a']++;

			maxi=max(maxi,freq[s[j]-'a']);

			int mini=INT_MAX;

			for(int k=0;k<26;k++){
				if(freq[k]>0){
					mini=min(mini,freq[k]);
				}
			}
			sum+=(maxi-mini);
		}
	}
	return sum;
}



