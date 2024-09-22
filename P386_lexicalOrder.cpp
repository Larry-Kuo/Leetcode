class Solution {
public:
    void dfs(int i, int n, vector<int> &ans) {
        if(i <= n)  ans.push_back(i);
        i *= 10;
        if(i > n) {
            return;
        }
        dfs(i, n, ans);
        for(int j = 1; j < 10; ++j) {
            dfs(i + j, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= min(n, 9); ++i) {
            dfs(i, n, ans);
        }
        return ans;
    }
};