class Solution {
public:
    bool res;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j){
        if(i >= grid2.size() || j >= grid2[i].size() || visited[i][j] || grid2[i][j] == 0){
            return;
        }
        if(grid1[i][j] == 0){
            res = false;
            return;
        }
        visited[i][j] = true;
        dfs(grid1, grid2, visited, i - 1, j);
        dfs(grid1, grid2, visited, i + 1, j);
        dfs(grid1, grid2, visited, i, j - 1);
        dfs(grid1, grid2, visited, i, j + 1);
        return;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid1[i][j] == 1 && grid2[i][j] == 1 && !visited[i][j]){
                    res = true;
                    dfs(grid1, grid2, visited, i, j);
                    if(res){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};