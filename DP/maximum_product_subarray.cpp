/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 
*/




class Solution {

public:

    int maxProduct(vector<int>& nums) {

        int mmax = nums[0];

        int mmin = nums[0];

        int res = nums[0];

        for(int i = 1; i < nums.size(); i ++){

            int tmp = mmax;

            mmax = max(max(tmp*nums[i], mmin*nums[i]), nums[i]);

            mmin = min(min(tmp*nums[i], mmin*nums[i]), nums[i]);

            res = max(res, mmax);

        }

        return res;

    }

};
