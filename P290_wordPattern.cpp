class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        unordered_map<string, char> umap2;
        vector<string> sVec;
        auto sit = s.begin();
        while(sit!=s.end()){
            if(*sit==' '){
                sit++;
            }
            string tmp;
            while(*sit!=' '&&sit!=s.end()){
                tmp += *sit;
                sit++;
            }
            sVec.push_back(tmp);
        }
        for(auto &it: sVec){
            cout << it << endl;
        }
        if(sVec.size()!=pattern.length()){
            return false;
        }
        int cnt = 0;
        for(auto &it: pattern){
            if(umap.find(it)!=umap.end()){
                if(umap.find(it)->second!=sVec[cnt]){
                    return false;
                }
            }
            else{
                if(umap2.find(sVec[cnt])==umap2.end()){
                    umap2.insert({sVec[cnt], it});
                    umap.insert({it, sVec[cnt]});
                }
                else{
                    return false;
                }
            }
            cnt++;
        }
        return true;
    }
};