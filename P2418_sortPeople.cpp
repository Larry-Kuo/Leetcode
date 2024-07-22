class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string, greater<int>> map;
        vector<string> ans;
        for(int i = 0; i < names.size(); ++i){
            map.insert({heights[i], names[i]});
        }
        for(auto &it: map){
            ans.push_back(it.second);
        }
        return ans;
    }
};