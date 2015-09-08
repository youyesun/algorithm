/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1

Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]

Example 2

Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10

Output: [-34, -14, -10, -10, 10]
*/

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string,vector<int>> dp;
        return helper(input, dp);
    }
    
    vector<int> helper(string input, unordered_map<string,vector<int>> &dp){
        vector<int> result;
        for(int i=0; i<input.length(); i++){
            if((input[i] == '+') || (input[i] == '-') || (input[i] == '*')){
                vector<int> res1;
                vector<int> res2;
                string sub1 = input.substr(0,i);
                res1 = dp.find(sub1)!=dp.end()?dp[sub1]:helper(sub1,dp);
                string sub2 = input.substr(i+1);
                res2 = dp.find(sub2)!=dp.end()?dp[sub2]:helper(sub2,dp);
                for(auto n1 : res1)
                    for(auto n2: res2){
                        if(input[i] == '+')
                            result.push_back(n1+n2);
                        if(input[i] == '-')
                            result.push_back(n1-n2);
                        if(input[i] == '*')
                            result.push_back(n1*n2);
                    }
            }
        }
        if(result.empty())
            result.push_back(atoi(input.c_str()));
        dp[input] = result;
        return result;
    }
};
