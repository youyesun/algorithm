/*Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        vector<int> mark(26,0);
        for(int i = 0; i < s.length(); i++){
            mark[s[i] - 'a'] ++;
            mark[t[i] - 'a'] --;
        }    

        for(int i = 0; i < 26; i ++)
            if(mark[i] != 0)
                return false;
        return true;
    }
};
