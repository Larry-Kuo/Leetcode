class Solution {
public:
    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &visit, int i, int j){
        if(matrix[i][j] == 1 || visit[i][j] == 1){
            return;
        }
        visit[i][j] = 1;
        if(i > 0){
            dfs(matrix, visit, i - 1, j);
        }
        if(j > 0){
            dfs(matrix, visit, i, j - 1);
        }
        if(i < matrix.size() - 1){
            dfs(matrix, visit, i + 1, j);
        }
        if(j < matrix[i].size() - 1){
            dfs(matrix, visit, i, j + 1);
        }
        return;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<vector<int>> matrix (3 * n, vector<int> (3 * n, 0));
        vector<vector<int>> visit (3 * n, vector<int> (3 * n, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '/'){
                    matrix[3 * i][3 * j + 2] = 1;
                    matrix[3 * i + 1][3 * j + 1] = 1;
                    matrix[3 * i + 2][3 * j] = 1;
                }
                else if(grid[i][j] == '\\'){
                    matrix[3 * i][3 * j] = 1;
                    matrix[3 * i + 1][3 * j + 1] = 1;
                    matrix[3 * i + 2][3 * j + 2] = 1;
                }
            }
        }

        for(int i = 0; i < 3 * n; ++i){
            for(int j = 0; j < 3 * n; ++j){
                if(matrix[i][j] == 0 && visit[i][j] == 0){
                    dfs(matrix, visit, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};