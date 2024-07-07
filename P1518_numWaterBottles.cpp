class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0, empty = 0;
        while(numBottles>0){
            empty += numBottles;
            ans += numBottles;
            numBottles = 0;
            if(empty>=numExchange){
                numBottles += (empty/numExchange);
                empty = empty % numExchange;
            }
        }
        return ans;
    }
};