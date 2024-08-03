class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int n = target.size();
        vector<int> vec1 (1001, 0);
        vector<int> vec2 (1001, 0);
        for(int i = 0; i < n; ++i){
            vec1[target[i]]++;
            vec2[arr[i]]++;
        }

        return (vec1==vec2) ? true : false;
    }
};