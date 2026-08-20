// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int level=0;
        for(int ch:s){
            if(ch=='('){
                if(level>0)
                   result+=ch;
                level++;
            }
            else if(ch==')'){
                level--;
                if(level>0)
                   result+=ch;
            }
        }
        return result;
    }
};

// Input: s = "(()())(())"
// Output: "()()()"
// Explanation: 
// The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
// After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


// Input: s = "(()())(())(()(()))"
// Output: "()()()()(())"
// Explanation: 
// The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
// After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

// Input: s = "()()"
// Output: ""
// Explanation: 
// The input string is "()()", with primitive decomposition "()" + "()".
// After removing outer parentheses of each part, this is "" + "" = "".




//valid parantheis

bool isValidParenthesis(string s)
{
    stack<char>st;

    for(char ch:s){
        if(ch=='(' || ch=='{' || ch=='[')
           st.push(ch);
        else{
            if(st.empty())
               return false;
            char top=st.top();
            if(ch==')' && top!='(' || ch=='}' && top!='{' || ch==']' && top!='[')
               return false;
            st.pop();
        }

    }
        return st.empty();
}