/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


class Solution {

public:

    int maxProfit(vector<int>& prices) {

        int maxpro = 0;

        int minp = INT_MAX;

        for(int i = 0; i < prices.size(); i++){

            maxpro = max(maxpro, prices[i] - minp);

            minp = min(minp, prices[i]);

        }

        return maxpro;

    }

};
