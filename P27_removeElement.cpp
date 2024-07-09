class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size()-1;
        if(nums.size()==1){
            return nums[0]!=val;
        }
        while(l<=r){
            while(nums[r]==val&&r>0){
                r--;
            }
            if(nums[l]==val&&l<=r){
                swap(nums[l], nums[r]);
                r--;
            }
            l++;
        }
        return r+1;
    }
};