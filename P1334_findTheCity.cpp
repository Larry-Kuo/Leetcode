class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph (n);
        vector<vector<int>> shortest (n, vector<int> (n, INT_MAX));

        for(auto &it: edges){//build the graph
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
            shortest[it[0]][it[1]] = it[2];
            shortest[it[1]][it[0]] = it[2];
        }
        for(int i = 0; i < n; i++){
            vector<bool> visited(n);
            int city = 0;
            int before = 0;
            int minWeight, minEdge;
            do{
                minWeight = INT_MAX;
                visited[city] = true;
                for(auto &it: graph[city]){
                    if(it.first == i){
                        continue;
                    }
                    if(shortest[i][it.first] > it.second + before){
                        shortest[i][it.first] = it.second + before;
                    }
                }
                for(int e = 0; e < shortest[i].size(); ++e){
                    if(minWeight > shortest[i][e] && !visited[e]){
                        minWeight = shortest[i][e];
                        minEdge = e;
                    }
                }
                city = minEdge;
                before = minWeight;
            }while(minWeight!=INT_MAX);
        }
        int ans;
        int ansCnt = INT_MAX;
        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = 0; j < n; ++j){
                if(shortest[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(ansCnt >= cnt){
                ans = i;
                ansCnt = cnt;
            }
        }
        return ans;
    }
};