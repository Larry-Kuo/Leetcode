class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        for(int i = 0; i < matrix.size(); ++i){ //N*(N+M)
            int minimum = INT_MAX;
            int minimumPos;
            bool lucky = true;
            //every row
            for(int j = 0; j < matrix[i].size(); ++j){
            //every number in each rows
                if(matrix[i][j] < minimum){
                    minimumPos = j;
                    minimum = matrix[i][j];
                }
            }
            //found minimum in each rows
            for(int k = 0; k < matrix.size(); ++k){
                if(matrix[k][minimumPos] > minimum){
                    lucky = false;
                    break;
                }
            }
            if(lucky){
                ans.push_back(matrix[i][minimumPos]);
            }
        }
        return ans;
    }
};