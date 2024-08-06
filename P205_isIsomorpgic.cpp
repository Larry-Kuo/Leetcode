class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        map<char, char> map1;
        map<char, char> map2;
        for(int i = 0; i < n; ++i){
            char c1 = s[i];
            char c2 = t[i];
            if(map1.find(c1) != map1.end() || map2.find(c2) != map2.end()){
                if(map1[c1] != c2 || map2[c2] != c1){
                    return false;
                } 
            }
            else{
                map1.insert({c1, c2});
                map2.insert({c2, c1});
            }
        }
        return true;
    }
};