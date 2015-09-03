/*Description:

Count the number of prime numbers less than a non-negative number, n.
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        vector<bool> mark(n,false);
        int roof = sqrt(n);
        int sum = 1;
        for(int i = 3; i <n ; i += 2){
            if(!mark[i]){
                sum++;
                if(i > roof)
                    continue;
                for(int j = i*i; j< n; j+=i)
                    mark[j] = true;
            }
        }
        return sum;
    }
};
