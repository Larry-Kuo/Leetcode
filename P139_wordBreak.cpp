class Solution {
public:
    bool helper(string& s, unordered_set<string>& dict, vector<int>& dp, int start) {
        if (start == s.length()) return true;
        if (dp[start] != -1) return dp[start];
        
        for (int end = start + 1; end <= s.length(); end++) {
            if (dict.find(s.substr(start, end - start)) != dict.end() && helper(s, dict, dp, end)) {
                return dp[start] = 1;
            }
        }
        
        return dp[start] = 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return helper(s, dict, dp, 0);
    }
};