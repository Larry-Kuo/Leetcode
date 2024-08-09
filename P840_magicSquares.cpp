class Solution {
public:
    bool isMagic(int row, int col, vector<vector<int>> & grid){
        if(grid[row][col] != 5){
            return false;
        }
        bitset<10> once;
        vector<int> rowSum (3, 0);
        vector<int> colSum (3, 0);
        for(int i = row - 1; i <= row + 1; ++i){
            for(int j = col - 1; j <= col + 1; ++j){
                int x = grid[i][j];
                if(x < 1 || x > 9){
                    return false;
                }
                rowSum[i - row + 1] += x;
                colSum[j - col + 1] += x;
                once.flip(x);
            }
        }

        if(once.count() != 9)   return false;

        for(int i = 0; i < 3; ++i){
            if(rowSum[i] != 15 || colSum[i] != 15){
                return false;
            }
        }

        if(grid[row - 1][col - 1] + grid[row + 1][col + 1] != 10
        || grid[row - 1][col + 1] + grid[row + 1][col - 1] != 10){
            return false;
        }
        return true;

    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        if(rows < 3 || cols < 3){
            return ans;
        }
        for(int i = 1; i < rows - 1; ++i){
            for(int j = 1; j < cols - 1; ++j){
                if(isMagic(i, j, grid)){
                    ans ++;
                }
            }
        }
        return ans;
    }
};