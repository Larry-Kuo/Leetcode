class Solution {
public:
    void dfs(vector<vector<int>>& stones, vector<bool>& visited, int idx) {
        visited[idx] = true;
        for (int i = 0; i < stones.size(); ++i) {
            if (!visited[i] && (stones[i][0] == stones[idx][0] || stones[i][1] == stones[idx][1])) {
                dfs(stones, visited, i);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<bool> visited(n, false);
        int components = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(stones, visited, i);
                components++;
            }
        }
        
        return n - components;
    }
};
