class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double, int>>> graph(n);
        vector<double> shortest(n, -1.00);
        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < edges.size(); ++i){
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        pq.push({1, start_node});
        
        while(!pq.empty()){

            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &neigh: graph[node]){
                double neiProb = neigh.first;
                int nei = neigh.second;
                if(neiProb * prob > shortest[nei]){
                    shortest[nei] = neiProb * prob;
                    pq.push({neiProb * prob, nei});
                }
            }
        }

        return shortest[end_node] > 0 ? shortest[end_node] : 0;
    }
};