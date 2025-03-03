class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int incCount = 0;
        sort(nums.begin(), nums.end());
        for(int i =1; i < nums.size(); ++i){
            if(nums[i]<=nums[i-1]){
                incCount += (nums[i-1]+1)-nums[i];
                nums[i] = nums[i-1]+1;
            }
        }
        return incCount;
    }
};