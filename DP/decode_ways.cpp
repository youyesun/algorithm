/*
 A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2. 
*/


class Solution {

public:

    int numDecodings(string s) {

        int ss = s.length();

        if(ss == 0 || s[0] == '0')

            return 0;

        int dp[ss];

        dp[0] = 1;

        for(int i = 1; i < ss; i ++){

            if(s[i] != '0'){

                dp[i] = dp[i - 1];

                if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))

                    dp[i] += i >= 2? dp[i-2] : 1;

            }else{

                dp[i] = 0;

                if(s[i - 1] == '1' || s[i - 1] == '2')

                    dp[i] = i >= 2? dp[i-2] : 1;           }

            

        }

        return dp[ss - 1];

    }

};
