class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> counts(n+2, 0);
        for(auto i: edges){
            counts[i[0]]++;
            counts[i[1]]++;
        }
        for(int i =0; i <counts.size(); ++i){
            if(counts[i]==n)    return i;
        }
        return -1;
    }
};