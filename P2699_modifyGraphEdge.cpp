class Solution {
public:
    int dijkstra(int n, vector<vector<pair<int, int>>>& graph, int source, int dest){
        vector<int> shortest(n, INT_MAX);
        priority_queue<pair<int, int>> pq;
        pq.push({0, source});
        
        while(!pq.empty()){

            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &neigh: graph[node]){
                int neiWeight = neigh.first;
                int nei = neigh.second;
                if(weight + neiWeight < shortest[nei]){
                    shortest[nei] = weight + neiWeight;
                    pq.push({weight + neiWeight, nei});
                }
            }
        }
        return shortest[dest];
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int dest, int target) {
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < edges.size(); ++i){
            if(edges[i][2] == -1)   continue;
            graph[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            graph[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }

        int dOriginal = dijkstra(n, graph, source, dest);
        if(dOriginal < target){
            return {};
        }
        else if(dOriginal == target){
            for(auto &edge: edges){
                if(edge[2] == -1)   edge[2] = 2e9;
            }
            return edges;
        }
        else{
            //Iterate all modifiable edges to achieve target
            for(auto &edge: edges){
                //Skip non modifiable edges
                if(edge[2] != -1)   continue;
                //Assign 1 to all the modifiable edges till we find an answer
                edge[2] = 1;
                graph[edge[0]].push_back({edge[2], edge[1]});
                graph[edge[1]].push_back({edge[2], edge[0]});
                //Recalculate the distance
                int dNew = dijkstra(n, graph, source, dest);
                //Check if target is meet
                if(dNew <= target){
                    edge[2] += target - dNew;
                    int modify = target - dNew + 1;
                    for(auto &resEdge: edges){
                        if(resEdge[2] == -1)   resEdge[2] = 2e9;
                    }
                    return edges;
                }
            }
            return {};
        }
    }
};