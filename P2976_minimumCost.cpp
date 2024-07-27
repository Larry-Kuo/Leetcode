class Solution {
public:
    int convert(char c){
        return c - 'a';
    } 
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        long long ans = 0;
        vector<vector<pair<int, int>>> graph (26); // 26 alphabets
        vector<vector<int>> shortest (26, vector<int> (26, INT_MAX));
        for(int i = 0; i < n; ++i){
            graph[convert(original[i])].push_back({cost[i], convert(changed[i])});
        }

        for(int i = 0; i < n; ++i){
            int ci = convert(original[i]);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, ci});
            shortest[ci][ci] = 0;
            while(!pq.empty()){
                int alpha = pq.top().second;
                int dist = pq.top().first;
                pq.pop();
                for(auto &neigh: graph[alpha]){
                    int weight = neigh.first;
                    int neighAlpha = neigh.second;
                    if(shortest[ci][neighAlpha] > dist + weight){
                        shortest[ci][neighAlpha] = dist + weight;
                        pq.push({dist + weight, neighAlpha});
                    }
                }
            }
        }

        for(int i = 0; i < source.size(); ++i){
            if(source[i] == target[i]){
                continue;
            }
            long long operationCost = shortest[convert(source[i])][convert(target[i])];
            if(operationCost == INT_MAX){
                return -1;
            }
            else{
                ans += operationCost;
            }
        }

        return ans;
    }
};