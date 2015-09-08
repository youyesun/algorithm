/* Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number. */
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=0)
            return 0;
        if(n == 1)
            return 1;
        vector<int> mark(n);
        mark[0]=1;
        int t2 = 0, t3 = 0, t5 = 0;
        for(int i = 1; i < n ; i++){
            mark[i]=min(mark[t2]*2,min(mark[t3]*3,mark[t5]*5));
            if(mark[i] == mark[t2]*2) t2 ++;
            if(mark[i] == mark[t3]*3) t3 ++;
            if(mark[i] == mark[t5]*5) t5 ++;
        }
        return mark[n-1];
    }
};
