class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            int width = 0, height = 0;
            
            for (int j = i - 1; j >= 0 && width + books[j][0] <= shelfWidth; j--) {
                width += books[j][0];
                height = max(height, books[j][1]);
                dp[i] = min(dp[i], dp[j] + height);
            }
        }
        
        return dp[n];
    }
};