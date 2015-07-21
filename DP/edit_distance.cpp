/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/



class Solution {

public:

    int minDistance(string word1, string word2) {

       int s1 = word1.length();

       int s2 = word2.length();

       vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));

       for(int i = 0; i <= s1; i++)

            dp[i][0] = i;

       for(int j = 0; j <= s2; j++)

            dp[0][j] = j;

       for(int i = 1; i <= s1; i ++){

           for(int j = 1; j <= s2; j++){

               dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + (word1[i-1] == word2[j-1]? 0:1));

           }

       }

       return dp[s1][s2];



    }

};
