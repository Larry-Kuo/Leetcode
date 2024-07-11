class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        long long sum = 0;
        vector<long long> edges (n, 0);
        for(int vy = 0; vy < roads.size(); ++vy){
            for(int vx = 0; vx < 2; ++vx){
                edges[roads[vy][vx]]++;
            }
        }
        sort(edges.begin(), edges.end());
        for(int i = 1; i<=n; ++i){
            sum += i*edges[i-1];
        }
        return sum;
    }
};