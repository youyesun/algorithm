//You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

//Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

//Time: O(n)	Space: O(1)

class Solution {
    public:
        int rob(vector<int>& nums) {
            int rob = 0;
            int norob = 0;
            int tmp = 0;
            for(int m : nums){
                tmp = rob;
                rob = max(norob + m, rob);
                norob = tmp;
            }
            return max(norob, rob);
        }

}
