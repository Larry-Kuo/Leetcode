class Solution {
public:
    int convert(char c){
        return c - 'a';
    }
    bool equalFrequency(string word) {
        vector<int> vec(26, 0);
        map<int, int> map;
        int n = word.size();
        for(auto &c: word){
            vec[convert(c)]++;
        }
        for(auto &it: vec){
            if(it == 0){
                continue;
            }
            if(map.find(it) != map.end()){
                map[it]++;
            }
            else(map.insert({it, 1}));
        }
        if(map.size() == 1){
            pair<int, int> p1 = *map.begin();
            if(p1.first == 1 || p1.second == 1){
                return true;
            }
        }
        else if(map.size() == 2){
            pair<int, int> p1 = *map.begin();
            pair<int, int> p2 = *map.rbegin();
            if(p2.first - p1.first == 1 && p2.second == 1){
                return true;
            }
            else if((p1.first == 1 && p1.second == 1)||(p2.first == 1 && p2.second == 1)){
                return true;
            }
        }
        return false;
    }
};