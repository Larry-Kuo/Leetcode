class Solution {
public:
    int find(int u, vector<int> &parents){
        if(parents[u]==-1||u == parents[u]){
            parents[u] = u;
            return u;
        }
        else{
            return parents[u] = find(parents[u], parents);
        }
    }
    void combine(int u, int v, vector<int> &parents, vector<long> &size){
        u = find(u, parents);
        v = find(v, parents);

        if(u==v){
            return;
        }
        else{
            if(size[u]>size[v]){
                parents[v] = u;
                size[u]+=v;
            }
            else{
                parents[u] = v;
                size[v] += u;
            }
        }
    }


    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<vector<int>> alice, bob, charlie;
        vector<int> aliceParents(n+1,-1), bobParents(n+1,-1), charlieParents(n+1,-1);
        vector<long> aliceSize(n+1,1), bobSize(n+1,1), charlieSize(n+1,1);
        int usedEdges = 0;
        for(auto &it: edges){
            switch(it[0]){
                case 1:
                    alice.push_back(it);
                    break;
                case 2:
                    bob.push_back(it);
                    break;
                case 3:
                    if(find(it[1], charlieParents)!=find(it[2], charlieParents)){
                        combine(it[1], it[2], charlieParents, charlieSize);
                        usedEdges++;
                    }
                    combine(it[1], it[2], aliceParents, aliceSize);
                    combine(it[1], it[2], bobParents, bobSize);
                    break;
                default:
                    break;
            }
        }
        for(auto &it: alice){
            if(find(it[1], aliceParents)!=find(it[2], aliceParents)){
                combine(it[1], it[2], aliceParents, aliceSize);
                usedEdges++;
            }
        }
        for(auto &it: bob){
            if(find(it[1], bobParents)!=find(it[2], bobParents)){
                combine(it[1], it[2], bobParents, bobSize);
                usedEdges++;
            }
        }
        for(int i =1; i<n; ++i){
            if(find(i, aliceParents)!=find(i+1, aliceParents)||find(i, bobParents)!=find(i+1, bobParents)){
                return -1;
            }
        }
        return edges.size() - usedEdges;
    }
};