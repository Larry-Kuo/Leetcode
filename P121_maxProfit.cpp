class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        if(n == 1){
            return 0;
        }
        vector<int> dp (n);
        dp[0] = {prices[0]};
        for(int i = 1; i < n; ++i){
            dp[i] = min(prices[i], dp[i - 1]);
            ans = max(prices[i] - dp[i], ans);
        }
        return ans;
    }
};