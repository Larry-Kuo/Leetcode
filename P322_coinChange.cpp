class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
            return 0;
        }
        vector<int> dp (amount + 1, INT_MAX);
        int cnt = 0;
        int sum = 0;
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(i >= coins[j] && dp[i - coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};