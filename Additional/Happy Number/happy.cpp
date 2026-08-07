class Solution {
public:
      
    int squareofdigit(int n){
        int prod=0;
        while(n>0){
            int ld=n%10;
            prod+=(ld*ld);
            n=n/10;
        }
        return prod;
    }
    
    bool isHappy(int n) {
       while(n!=1 && n!=4){
         n=squareofdigit(n);
       }
       return n==1;
    }
};


Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:

Input: n = 2
Output: false