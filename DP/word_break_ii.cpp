/*
 Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 
*/



class Solution {

public:

    void collect(vector<vector<int>> mark, vector<string>& res, string s, int start, string tmp){

        for(auto stop : mark[start]){

            string sstr = s.substr(start, stop - start);

            string newtmp = start == 0 ? sstr : tmp + " "+ sstr;

            if(stop == s.length())

                res.push_back(newtmp);

            else collect(mark, res, s, stop, newtmp);

        }

    }



    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {

        int ss = s.length();

        vector<vector<int>> mark(ss, vector<int>());

        for(int stop = ss; stop >= 0; stop --){

            if(stop < ss && mark[stop].empty()) continue;

            for(int start = stop -1; start >= 0; start --)

                if(wordDict.count(s.substr(start, stop - start)))

                    mark[start].push_back(stop);

        }

        vector<string> res;

        collect(mark, res, s, 0, "");

        return res;

    }

};
