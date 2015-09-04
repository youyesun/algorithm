/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; i++){
            vector<int> tmp(i+1,0);
            tmp[0]=1;
            for(int j=1; j<i+1; j++){
                for(int k=j; k >=1; k--)
                    tmp[k] = tmp[k] + tmp[k-1];
            }
            res.push_back(tmp);
        }
        return res;
    }
};
