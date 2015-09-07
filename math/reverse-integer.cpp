/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321 
*/

class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        int sign = x >=0 ? 1: -1;
        x = abs(x);
        while(x){
            res = res*10 + x%10;
            x /=10;
        }
        if(res*sign > INT_MAX || res*sign < INT_MIN)
            return 0;
        return sign*res;
    }
};
