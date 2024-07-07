class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int ans = 0, maxl = 0;
        vector <char> tmp;
        while(r<s.size()){
            auto it = std::find(tmp.begin(), tmp.end(), s[r]);
            if(it!=tmp.end()){
                while(s[l]!=s[r]){
                    l++;
                    tmp.erase(tmp.begin());
                }
                l++;
                tmp.erase(tmp.begin());
                tmp.push_back(s[r]);
                maxl = tmp.size();
            }
            else{
                tmp.push_back(s[r]);
                maxl++;
            }
            ans = max(ans, maxl);
            r++;
        }
        return ans;
    }
};