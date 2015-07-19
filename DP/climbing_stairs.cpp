/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top? 
*/


class Solution {

public:

    int climbStairs(int n) {

        if(n <= 0) return 0;

        if(n == 1) return 1;

        if(n == 2) return 2;

        int one_step_away = 2;

        int two_step_away = 1;

        int tmp = 0;

        for(int i = 2; i < n; i++){

            tmp = one_step_away + two_step_away;

            two_step_away = one_step_away;

            one_step_away = tmp;

        }

        return one_step_away;

    }

};
