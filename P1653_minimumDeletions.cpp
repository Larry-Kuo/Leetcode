class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> dp (n + 1);
        int bCnt = 0;
        dp[0] = 0;
        for(int i = 1; i < n + 1; ++i){
            if(s[i - 1] == 'b'){
                dp[i] = dp[i - 1];
                bCnt++;
            }
            else{
                dp[i] = min(dp[i - 1] + 1, bCnt);
            }
        }
        return dp[n];
    }
};