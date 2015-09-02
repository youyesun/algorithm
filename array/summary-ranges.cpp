/*
 Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 

*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;

        for(int i = 0; i < nums.size(); ){
            int left = i;
            int right = i;
            while(right+1<nums.size() && nums[right+1]==nums[right]+1)
                right ++;
            string r = left == right? to_string(nums[left]):to_string(nums[left])+"->"+to_string(nums[right]);
            res.push_back(r);
            i = right + 1;
        }
        return res;
    }
};
