/*
Implement atoi to convert a string to an integer.
*/
class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(str[i]==' ')
            i++;
        int sign = 1;
        if(str[i] == '-'){
            sign = -1;
            i++;
        }else if(str[i]=='+'){
            i++;
        }
        long long res = 0;
        while(i<str.size() && str[i] >= '0' && str[i] <= '9'){
            res = 10*res + str[i] - '0';
            if(sign*res>INT_MAX)
                return INT_MAX;
            if(sign*res<INT_MIN)
                return INT_MIN;
            i++;
        }
        return sign*res;
    }
};
