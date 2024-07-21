class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int l = newInterval[0];
        int r = newInterval[1];
        int lbound, rbound;
        bool overlapped = false;
        vector<vector<int>> ans;
        vector<vector<int>> overlaps;
        if(n==0){
            ans.push_back(newInterval);
            return ans;
        }
        for(auto &it: intervals){
            if(l > it[1] || r <it[0]){
                ans.push_back(it);
            }
            else{
                //overlapped
                if(!overlapped){
                    ans.push_back({-1, -1});
                }
                overlapped = true;
                overlaps.push_back(it);
            }
        }
        if(overlapped){
            lbound = min(l, overlaps[0][0]);
            rbound = max(r, overlaps[overlaps.size()-1][1]);
            for(auto &it: ans){
                if(it[0]==-1){
                    it = {lbound, rbound};
                    break;
                }
            }
        }
        else{
            vector<int> newVec {l, r};
            for(int i=0; i<n-1; ++i){
                if(l > intervals[i][1] && r < intervals[i+1][0]){
                    ans.insert(next(ans.begin(),i+1), newVec);
                    return ans;
                }
            }
            if(r < ans[0][0]){
                ans.insert(ans.begin(), newVec);
            }
            else if(l > ans[n-1][1]){
                ans.push_back(newVec);
            }
        }
        return ans;
    }
};