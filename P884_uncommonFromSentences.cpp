class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> ans;
        map <string, int> M;
        string word;
        for(int i = 0; i <= s1.length(); ++i) {
            if(s1[i] == ' ' || i == s1.length()){
                if(M.find(word) != M.end()){
                    M[word]++;
                }
                else{
                    M[word] = 1;
                }
                word = "";
            }
            else{
                word += s1[i];
            }
        }
        word = "";
        for(int i = 0; i <= s2.length(); ++i) {
            if(s2[i] == ' ' || i == s2.length()){
                if(M.find(word) != M.end()){
                    M[word]++;
                }
                else{
                    M[word] = 1;
                }
                word = "";
            }
            else{
                word += s2[i];
            }
        }

        for(auto &words: M){
            if(words.second == 1) {
                ans.push_back(words.first);
            }
        }

        return ans;
    }
};