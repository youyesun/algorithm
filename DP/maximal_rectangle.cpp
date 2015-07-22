/*

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area. 
*/




class Solution {

public:

    int maximalRectangle(vector<vector<char>>& matrix) {

        if(matrix.empty()) return 0;

        int m = matrix.size();

        int n = matrix[0].size();

        vector<int> left(n, 0);

        vector<int> right(n, n);

        vector<int> height(n, 0);

        int curleft = 0;

        int curright = n;

        int maxa = 0;

        for(int i = 0; i < m; i++){

            curleft = 0;

            curright = n;

            for(int j = 0; j < n; j ++){

                if(matrix[i][j] == '1')

                    height[j] ++;

                else

                    height[j] = 0;

            }

            for(int j = 0; j < n; j ++){

                if(matrix[i][j] == '1')

                    left[j] = max(left[j], curleft);

                else{

                        left[j] = 0;

                        curleft = j+1;

                    }

            }

            for(int j = n -1; j >= 0; j --){

                if(matrix[i][j] == '1')

                    right[j] = min(right[j], curright);

                else{

                    right[j] = n;

                    curright = j;

                } 

            }

            for(int j = 0 ; j < n; j ++){

                maxa = max(maxa, (right[j] - left[j])*height[j]);

            }

        }

        

        return maxa;

    }

};
