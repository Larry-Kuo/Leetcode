class Solution {
public:
    void push(int rows, int cols, int row, int col, vector<vector<int>> & vec){
        if((row < rows) && (row >= 0) && (col < cols) && (col >= 0)){
            vec.push_back({row, col});
        }
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        int D = max(max(abs(rows - 1 - rStart), rStart), max(cStart, abs(cols - 1 - cStart)));
        int row = rStart, col = cStart;
        ans.push_back({row, col}); // push starting point
        for(int d = 1; d <= D; ++d){
            //every time we enters a loop, move to the right one step
            col = col + 1;
            push(rows, cols, row, col, ans);
            //down (-1 + 2 * d) times
            for(int i = 0; i < (-1 + 2 * d); ++i){
                row ++;
                push(rows, cols, row, col, ans);
            }
            //left 2 * d times
            for(int i = 0; i < 2 * d; ++i){
                col --;
                push(rows, cols, row, col, ans);
            }
            //up 2 * d times
            for(int i = 0; i < 2 * d; ++i){
                row --;
                push(rows, cols, row, col, ans);
            }
            //right 2 * d times
            for(int i = 0; i < 2 * d; ++i){
                col ++;
                push(rows, cols, row, col, ans);
            }
        }
        return ans;
    }
};