class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int cnt = 1;
        unordered_map<string, int> map;
        for(auto &s: arr){
            map[s]++;
        }
        for(auto &s: arr){
            if(map[s] == 1){
                if(cnt== k) return s;
                cnt++;
            }
        }

        return "";
    }
};