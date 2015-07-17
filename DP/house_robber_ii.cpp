/*After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/

class Solution {

public:



    int rob(vector<int>& nums, int left, int right){

        int rob = 0;

        int notrob  = 0;

        int tmp = 0;

        for(int i = left; i <= right; i++){

            tmp = rob;

            rob = max(rob, notrob + nums[i]);

            notrob = tmp;

        }

        return max(rob, notrob);

    }



    int rob(vector<int>& nums) {

        int ss = nums.size();

        if(ss == 1) return nums[0];

        return max( rob(nums, 0, ss - 2), rob(nums, 1, ss - 1));

    }

};
