/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
*/


class Solution {

public:

    int longestValidParentheses(string s) {

        int ss = s.length();

        if(ss <= 1) return 0;

        int curmax = 0;

        vector<int> dp(ss,0);

        for(int i = 1; i < ss; i++){

            if(s[i] == ')' && (i - dp[i-1] -1 >= 0) && (s[i - dp[i-1] -1] == '(')){

                dp[i] = dp[i-1] + 2 + (i - dp[i-1] - 2 >= 0? dp[i - dp[i-1] - 2]:0);

                curmax = max(curmax, dp[i]);   

            }

            

        }

        return curmax;

        

    }

};
