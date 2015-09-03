/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while(n){
            n-=1;
            res = (char)(('A' + (n)%26)) + res;
            n/=26;
        }
        return res;
    }
};
