/*
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false. 
*/


class Solution {

public:

    bool isInterleave(string s1, string s2, string s3) {

        int ss1 = s1.length();

        int ss2 = s2.length();

        int ss3 = s3.length();

        if(ss3 != (ss1 + ss2))

            return false;

        vector<vector<bool>> dp(ss1 + 1, vector<bool>(ss2 + 1, false));

        for(int i = 0; i <= ss1; i++){

            for(int j = 0; j <= ss2; j++){

                if(i == 0 && j == 0)

                    dp[i][j] = true;

                else if(i == 0 && j != 0)

                    dp[i][j] = dp[i][j-1] && (s2[j-1] == s3[i+j-1]);

                else if(j == 0 && i != 0)

                    dp[i][j] = dp[i-1][j] && (s1[i-1] == s3[i+j-1]);

                else

                    dp[i][j] = (dp[i][j-1] && (s2[j-1] == s3[i+j-1])) || (dp[i-1][j] && (s1[i-1] == s3[i+j-1]));

            }

        }

        return dp[ss1][ss2];

    }

};
