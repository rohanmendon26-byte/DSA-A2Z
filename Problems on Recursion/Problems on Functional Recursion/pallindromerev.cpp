// String is pallindrome or not
#include<iostream>
using namespace std;
//leetcode
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {

            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare lowercase characters
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }

//custom
// bool f(int i,string &s){
//     if(i>=s.size()/2)
//        return true;
//     if(s[i]!=s[s.size()-i-1])
//        return false;
//     f(i+1,s);
// }

int main()
{
    string s;
    s="radan";
    // cout<<f(0,s);
    cout<<isPalindrome(s);
    return 0;
}