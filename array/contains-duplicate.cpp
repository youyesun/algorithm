/*
Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct. 
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(auto i : nums){
            if(m.find(i)!=m.end())
                return true;
            m.insert(i);
        }
        return false;
};
