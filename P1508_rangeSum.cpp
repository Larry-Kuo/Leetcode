class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            int sum = 0;
            for(int j = i; j < n; ++j){
                sum += nums[j];
                vec.push_back(sum);
            }
        }
        sort(vec.begin(), vec.end());
        for(int i = left - 1; i < right; ++i){
            ans += vec[i];
        }
        ans = ans % (1000000007);
        return ans;
    }
};