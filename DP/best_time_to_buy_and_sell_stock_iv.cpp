/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {

public:

    int maxProfit(int k, vector<int>& prices) {

        int ss = prices.size();

        if(k == 0 || ss < 2) return 0;

        if(k > ss/2){

            int maxpro = 0;

            for(int i = 1; i < ss; i++)

                if(prices[i] > prices[i - 1])

                    maxpro += prices[i] - prices[i - 1];

            return maxpro;

        }

        vector<int> hold(k, INT_MIN);

        vector<int> rel(k, 0);

        for(int i = 0 ; i < ss; i ++)

            for(int j = k - 1; j >=0; j --){

                rel[j] = max(rel[j], hold[j] + prices[i]);

                hold[j] = max(hold[j], (j > 0 ? rel[j - 1] : 0) - prices[i]);

            }

        return rel[ k - 1];

    }

};
