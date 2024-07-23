class Solution {
public:
    static bool compare(const pair<int, int> &p1, const pair<int, int> &p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first < p2.first;
    } 
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int, greater<int>> map;
        vector<pair<int, int>> vec;
        vector<int> ans;
        for(auto &it: nums){
            if(map.find(it) == map.end()){
                map.insert({it, 1});
            }
            else{
                map[it]++;
            }
        }

        for(auto &it: map){
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(), vec.end(), compare);
        
        for(auto &it: vec){
            vector<int> tmp(it.first, it.second);
            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }
        return ans;
    }
};