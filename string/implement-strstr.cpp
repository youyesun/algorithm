/*
 Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int pos = 0;
        while(pos <= int(haystack.length() - needle.length())){
            if(haystack.substr(pos,needle.length()) == needle)
                return pos;
            pos++;
            while((pos < int(haystack.length() - needle.length()))&&(haystack[pos]!=needle[0]))
                pos++;
        }
        return -1;
    }
};  
