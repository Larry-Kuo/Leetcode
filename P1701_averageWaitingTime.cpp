class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int cnt = 0, clk = 0;
        double sum = 0.0;
        while(cnt<customers.size()){
            if(clk<customers[cnt][0]){
                clk++;
            }
            else{
                clk+=customers[cnt][1];
                sum += clk - customers[cnt][0];
                cnt++;
            }
        }
        return (sum/customers.size());

    }
};