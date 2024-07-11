class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCnt = 0;
        for(auto &it: arr){
            if(it%2==1){
                oddCnt++;
                if(oddCnt==3){
                    return true;
                }
            }
            else{
                oddCnt = 0;
            }
        }
        return false;
    }
};