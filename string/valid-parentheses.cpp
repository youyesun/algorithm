/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s){
            if(i=='(')
                st.push(')');
            else if(i=='{')
                st.push('}');
            else if(i=='[')
                st.push(']');
                else if(!st.empty()&&st.top()==i)
                    st.pop();
                    else
                        return false;
        }
        return st.empty();
    }
};
