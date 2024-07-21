class Solution {
public:
    void dfs(int course, vector<vector<int>> &graph, vector<int> &indegree, vector<int> &ans){
        ans.push_back(course);
        indegree[course] = -1;
        for(auto &it: graph[course]){
            if(indegree[it]==1){
                indegree[it] = 0;
                dfs(it, graph, indegree, ans);
            }
            else{
                indegree[it]--;
            }
        }
    } 
    vector<int> findOrder(int n, vector<vector<int>>& vec) {
        vector<vector<int>> graph (n);
        vector<int> ans, indegree (n);
        for(auto &it: vec){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        for(int i = 0; i< indegree.size(); ++i){
            if(indegree[i]==0){
                dfs(i, graph, indegree, ans);
            }
        }
        if(ans.size()!=n){
            return {};
        }
        return ans;
    }
};