class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int target = 0 - nums[i];
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            //two sum problem
            map<int, int> m;
            for(int j = i + 1; j < nums.size(); ++j){
                if(m.find(nums[j]) != m.end()){
                    s.insert({nums[i], m[nums[j]], nums[j]});
                }
                else{
                    m[target - nums[j]] = nums[j];
                }
            }
        }

        vector<vector<int>> ans (s.begin(), s.end());
        return ans;
    }
};