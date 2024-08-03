class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp (n + 1, 1);
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i - 1; ++j){
                if(nums[i - 1] > nums[j]){
                    dp[i] = max(dp[i], dp[j + 1] + 1);
                }
            }
            ans = max(ans, dp[i]);
        } 
        return ans;
    }
};