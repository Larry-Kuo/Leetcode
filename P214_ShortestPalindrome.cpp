class Solution {
public:
    int LSP(const string &text, const string &pattern) {
        string temp = pattern + '#' + text;
        vector<int> LSP(temp.length(), 0);
        int i = 1, k = 0;
        while(i < temp.length()) {
            if(temp[i] == temp[k]) {
                k++;
                LSP[i] = k;
                i++;
            }
            else {
                if(k > 0) {
                    k = LSP[k - 1];
                }
                else {
                    LSP[i] = 0;
                    i++;
                }
            }
        }
        return LSP.back();
    }
    string shortestPalindrome(string s) {
        return string(s.rbegin(), s.rend()).substr(0, s.length() - LSP(string(s.rbegin(), s.rend()), s)) + s;      
    }
};