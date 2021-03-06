/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k<=0)
            return false;
        if(k >= nums.size())
             k = nums.size() - 1;
        unordered_set<int> s;
        for(int i = 0; i < nums.size(); i++){
            if(i > k)
                s.erase(nums[i - k - 1]);
            if(s.find(nums[i])!=s.end())
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};
