class Solution {
public:
    int calculate(int nodes, int change, int time){
        int total = 0;
        for(int i = 0; i < nodes; ++i){
            if(total % (2 * change) < change){
                total += time;
            }
            else{
                total += (2 * change - total % (2 * change));
                total += time;
            }
        }
        return total;
    }
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> graph (n+1);
        vector<pair<int, int>> shortest (n+1, {INT_MAX, INT_MAX}); 
        // the first one record the shortest and the second one record the second shortest
        for(auto &it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        queue<pair<int, int>> q;
        // the first record length and the second record node idx
        q.push({0, 1});
        while(!q.empty()){
            int node = q.front().second;
            int length = q.front().first;
            q.pop();
            vector<int> connect = graph[node];
            for(auto &it: connect){
                int neigh = it;
                int newLength = length + 1;
                if(newLength < shortest[neigh].first){
                    shortest[neigh].second = shortest[neigh].first;
                    shortest[neigh].first = newLength;
                    q.push({newLength, neigh});
                }
                else if(newLength > shortest[neigh].first && newLength < shortest[neigh].second){
                    shortest[neigh].second = newLength;
                    q.push({newLength, neigh});
                }
            }
        }
        return calculate(shortest[n].second, change, time);
    }
};