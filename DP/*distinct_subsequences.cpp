/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3. 
*/


class Solution {

public:

    int numDistinct(string s, string t) {

        if(s.size() < t.size())

            return 0;

        vector<int> dp(t.size() + 1, 0);

        dp[0] = 1;

        for(int i = 1; i <= s.size(); i ++)

            for( int j = t.size(); j >=1; j --)

                if(s[i - 1] == t[j - 1])

                    dp[j] += dp[j - 1];

        return dp[t.size()];

    }

};
