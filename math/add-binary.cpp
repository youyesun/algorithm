/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.size()-1;
        int bl = b.size()-1;
        int c = 0;
        string res = "";
        while(al>=0||bl>=0||c>0){
            int ad = al>=0?(a[al--]-'0'):0;
            int bd = bl>=0?(b[bl--]-'0'):0;
            res = to_string((ad+bd+c)%2) + res;
            c=(ad+bd+c)/2;
        }
        return res;
    }
};
