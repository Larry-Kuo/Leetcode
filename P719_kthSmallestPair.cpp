class Solution {
public:
    int count(vector<int> &nums, int mid){
        int cnt = 0, l = 0;
        for(int r = 1; r < nums.size(); ++r){
            while(nums[r] - nums[l] > mid){
                ++l;
            }
            cnt += r - l;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int minD = 0, maxD = nums.back() - nums.front();
        while(minD < maxD){
            int mid = minD + (maxD - minD) / 2;
            if(count(nums, mid) < k){
                minD = mid + 1;
            }
            else{
                maxD = mid;  
            }
        }
        return minD;
    }
};