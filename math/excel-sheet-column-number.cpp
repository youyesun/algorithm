/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
*/

class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int base = 1;
        for(int i = s.length()-1; i >= 0; i--){
            res += base*(s[i] - 'A' + 1);
            base *= 26;
        }
        return res;
    }
};
