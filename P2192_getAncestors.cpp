class Solution {
public:
    void dfs(vector<vector<int>>& rEdges, int i, int j, vector<vector<int>>& ans, vector<bool> &vis){
        vis[j] = true;
        for(auto &x: rEdges[j]){
            if(!vis[x]){
                ans[x].push_back(i);
                dfs(rEdges, i, x, ans, vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rEdges (n), ans (n);
        for(auto &it: edges){
            rEdges[it[0]].push_back(it[1]);
        }
        for(int i=0; i<n; ++i){
            vector <bool> vis (n);
            dfs(rEdges, i, i, ans, vis);
        }
        return ans;
    }
};