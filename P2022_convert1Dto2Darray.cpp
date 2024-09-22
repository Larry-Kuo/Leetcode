class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans (m, vector<int> (n));
        int row = 0;
        int col = 0;
        if(m * n < original.size() || m * n > original.size()){
            return {};
        }
        while(row < m){
            for(int i = 0; i < n; ++i){
                ans[row][i] = original[row * n + i];
            }
            row++;
        }
        return ans;
    }
};