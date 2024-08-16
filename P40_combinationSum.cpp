class Solution {
public:
    vector<vector<int>> ans;
    void helper(vector<int> &candidates, int start, int target, vector<int>& subset) {
        if (target == 0) {
            ans.push_back(subset);
            return;
        }
        
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            
            if (i > start && candidates[i] == candidates[i-1]) continue;
            
            subset.push_back(candidates[i]);
            helper(candidates, i + 1, target - candidates[i], subset);
            subset.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> subset;
        helper(candidates, 0, target, subset);
        return ans;
    }
};