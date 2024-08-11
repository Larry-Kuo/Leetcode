class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> & visit, int i, int j){
        if(grid[i][j] == 0 || visit[i][j]){
            return;
        }
        visit[i][j] = true;
        if(i > 0){
            dfs(grid, visit, i - 1, j);
        }
        if(j > 0){
            dfs(grid, visit, i, j - 1);
        }
        if(i < grid.size() - 1){
            dfs(grid, visit, i + 1, j);
        }
        if(j < grid[i].size() - 1){
            dfs(grid, visit, i, j + 1);
        }
        return;

    }

    int countIslands(vector<vector<int>>& grid){
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool> (m, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1 && !visit[i][j]){
                    cnt++;
                    dfs(grid, visit, i, j);
                }
            } 
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        int islandCnt = countIslands(grid);
        int n = grid.size();
        int m = grid[0].size();
        if(islandCnt != 1){
            return 0;
        }

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countIslands(grid) != 1){
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};