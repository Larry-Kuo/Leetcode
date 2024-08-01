class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for(auto &pass: details){
            if(stoi(pass.substr(11, 2)) > 60){
                ans++;
            }
        }
        return ans;
    }
};