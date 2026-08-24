class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        
        for(char ch:s){
            if(ch=='(' || ch=='[' || ch=='{')
               st.push(ch);
            else{
                if(st.empty())
                   return false;
                
                char top=st.top();
                
                if(ch==')'&& top!='(' || ch=='}' && top!='{' || ch==']' && top!='[')
                   return false;
                   
                st.pop();
            }
        }
        
        return st.empty();
    }
};


// Input: s = "[{()}]"
// Output: true
// Explanation: All the brackets are well-formed.

// Input: s = "[()()]{}"
// Output: true
// Explanation: All the brackets are well-formed.

// Input: s = "([]"
// Output: false
// Explanation: The expression is not balanced as there is a missing ')' at the end.

// Input: s = "([{]})"
// Output: false
// Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.