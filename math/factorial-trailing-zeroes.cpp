/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long long i = 5; i <= n; i*=5){
            res += n/i;
        }
        return res;
    }
};
