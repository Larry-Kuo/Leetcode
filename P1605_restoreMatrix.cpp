class Solution {
public:
    bool findMin(vector<int>& rowSum, vector<int> &colSum, int &r, int &c){
        int rmin = INT_MAX, cmin = INT_MAX;
        r = -1;
        c = -1;
        for(int i = 0; i < rowSum.size(); ++i){
            if(rowSum[i]!= 0 && rmin > rowSum[i]){
                rmin = rowSum[i];
                r = i;
            }
        }

        for(int i = 0; i < colSum.size(); ++i){
            if(colSum[i] != 0 && cmin > colSum[i]){
                cmin = colSum[i];
                c = i;
            }
        }
        return (r == -1 && c == -1) ? false : true;
    }

    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        int r = 0, c = 0;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        while(findMin(rowSum, colSum, r, c)){
            if(rowSum[r] <= colSum[c]){
                ans[r][c] = rowSum[r];
                colSum[c] -= rowSum[r];
                rowSum[r] = 0;
            }
            else{
                ans[r][c] = colSum[c];
                rowSum[r] -= colSum[c];
                colSum[c] = 0;
            }
        }
        return ans;
    }
};