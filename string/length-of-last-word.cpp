/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5. 
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        for(int i = 0 ; i < s.length(); i++){
            if(s[i]!=' ')
                l++;
            else if((i<(s.length()-1) )&&s[i+1]!=' ')
                l = 0;
        }
        return l;
    }
};
