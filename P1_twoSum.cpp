class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int target) {
        unordered_map<int, int> umap;
        for(int i = 0; i <vec.size(); ++i){
            auto itr = umap.find(vec[i]);
            if(itr!=umap.end()){
                return vector<int> {i, itr->second};
            }
            else{
                umap.insert({target-vec[i], i});
            }
        }
        return vector<int> {-1, -1};
    }
};