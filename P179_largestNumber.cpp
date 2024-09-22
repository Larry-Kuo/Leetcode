class Solution {
public:
    static bool customComparison(int a, int b) 
    { 
        // Custom comparison logic 
        string s1 = to_string(a);
        string s2 = to_string(b); 
        return s1+s2 > s2+s1;
    } 
    string largestNumber(vector<int>& nums) {
        string ans = "";
        if(count(nums.begin(), nums.end(), 0) == nums.size()) {
            return "0";
        }
        sort(nums.begin(), nums.end(), customComparison);
        for(auto &it: nums) {
            ans += to_string(it);
        }
        return ans;
    }
};