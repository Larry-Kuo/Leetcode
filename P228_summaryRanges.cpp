class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string arrow = "->";
        int n = nums.size();
        if(n==0){
            return ans;
        }
        else if(n==1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        else{
            string s;
            for(int i=0; i<n; ++i){
                if(i==n-1||nums[i]+1!=nums[i+1]){
                    s+=to_string(nums[i]);
                    ans.push_back(s);
                    s = "";
                }
                else if(i==0||nums[i-1]!=nums[i]-1){
                    s+=to_string(nums[i]);
                    s+=arrow;
                }
            }
        }
        return ans;
    }
};