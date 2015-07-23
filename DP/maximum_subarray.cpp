/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6. 
*/


class Solution {

public:

    int maxSubArray(vector<int>& nums) {

        int mmax = nums[0];

        int res = nums[0];

        for(int i = 1; i <nums.size(); i ++){

            mmax = max( mmax + nums[i], nums[i]);

            res = max(res, mmax);

        }

        return res;

    }

};
