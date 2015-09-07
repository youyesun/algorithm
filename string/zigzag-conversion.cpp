/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1)
            return s;
        string mark[numRows]={""};
        int step = 1;
        int row = 0;
        for(int i=0; i < s.length(); i++){
            mark[row] += s[i];
            if(row == 0)
                step = 1;
            if(row == numRows - 1)
                step = -1;
            row += step;
        }
        string res="";
        for(string st: mark)
            res+=st;
        return res;
    }
};
