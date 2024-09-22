class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        unordered_map <char, int> M = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int curr = 1;
        for(int i = s.length() - 1; i >= 0; --i) {
            char c = s[i];
            if(curr > M[c]) {
                ans -= M[c];
            }
            else {
                ans += M[c];
                curr = M[c];
            }
        }
        return ans;
    }
};