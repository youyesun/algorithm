/*
 Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code". 
*/
class Solution {

public:

    bool wordBreak(string s, unordered_set<string>& wordDict) {

        int ss = s.length();

        vector<bool> dp(ss + 1, false);

        dp[0] = true;

        for(int i = 1; i <= ss; i ++){

            for(int j = i - 1; j >= 0 ; j --)

                if(dp[j] && (wordDict.find(s.substr(j, i - j)) != wordDict.end())){

                    dp[i] = true;

                    break;

                }

        }

        return dp[ss];

    }

};
