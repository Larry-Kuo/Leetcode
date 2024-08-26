class Solution {
public:
    int helper(int n){
        for(int i = n / 2; i >= sqrt(i); --i){
            if(n % i == 0){
                return i;
            }
        }
        return 1;
    }
    int minSteps(int n) {
        vector<int> dp (n + 1);
        dp[1] = 0; // A requires 0 steps
        for(int i = 2; i < n + 1; ++i){
            int div = helper(i);
            int quo = i / div;
            dp[i] = dp[div] + quo;
        }
        return dp[n];
    }
};