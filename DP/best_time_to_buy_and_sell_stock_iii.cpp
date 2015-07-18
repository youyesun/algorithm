/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {

public:

    int maxProfit(vector<int> &prices) {

        int hold1 = INT_MIN;

        int hold2 = INT_MIN;

        int rel1 = 0;

        int rel2 = 0;

        for(int i : prices){

            rel2 = max(rel2, hold2 + i);

            hold2 = max(hold2, rel1 - i);

            rel1 = max(rel1, hold1 + i);

            hold1 = max(hold1, -i);

        }

        return rel2;

    }

};
