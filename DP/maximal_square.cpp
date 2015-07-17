/*

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.



For example, given the following matrix:



1 0 1 0 0

1 0 1 1 1

1 1 1 1 1

1 0 0 1 0



Return 4.

*/





class Solution {

public:

    int maximalSquare(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int m = matrix.size();

        int n = matrix[0].size();

        vector<int> dp(n + 1,0);

        int mmax = 0;

        for(int i = 0; i < m; i++){

            for(int j = 1; j <= n; j++){

                if(matrix[i][j - 1] == '1'){

                    int k = min(dp[j], dp[j - 1]);

                    dp[j] = matrix[i - k][j - k - 1] == '1'? k + 1: k;

                    mmax = max(mmax, dp[j]);

                }else dp[j] = 0;

            }

        }

        return mmax*mmax;

    }

};
