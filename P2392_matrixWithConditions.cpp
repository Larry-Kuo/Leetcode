class Solution {
public:
    void dfs(int num, vector<vector<int>> &graph, vector<int> &indegree, vector<int> &ans){
        if(num!=0){
            ans.push_back(num);
        }
        indegree[num] = -1;
        for(auto &it: graph[num]){
            if(indegree[it] == 1){
                dfs(it, graph, indegree, ans);
            }
            else{
                indegree[it]--;
            }
        }
    }
    int findPos(int num, vector<int> order){
        for(int i = 0; i < order.size(); ++i){
            if(num == order[i]){
                return i;
            }
        }
        return -1;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> indegreeRow (k+1);
        vector<int> indegreeCol (k+1);
        vector<vector<int>> graphRow (k+1);
        vector<vector<int>> graphCol (k+1);
        vector<int> rowOrder, colOrder;
        vector<vector<int>> ans (k, vector<int> (k, 0));
        for(auto &it: rowConditions){
            graphRow[it[0]].push_back(it[1]);
            indegreeRow[it[1]]++;
        }
        for(auto &it: colConditions){
            graphCol[it[0]].push_back(it[1]);
            indegreeCol[it[1]]++;
        }
        for(int i = 0; i < k+1; ++i){
            if(indegreeRow[i] == 0){
                dfs(i, graphRow, indegreeRow, rowOrder);
            }
        }
         for(int i = 0; i < k+1; ++i){
            if(indegreeCol[i] == 0){
                dfs(i, graphCol, indegreeCol, colOrder);
            }
        }
        if(rowOrder.size() < k || colOrder.size() < k){
            return {};
        }

        for(int i = 1; i < k+1; ++i){
            int rpos = findPos(i, rowOrder);
            int cpos = findPos(i, colOrder);
            ans[rpos][cpos] = i;
        }
        return ans;
    }
};