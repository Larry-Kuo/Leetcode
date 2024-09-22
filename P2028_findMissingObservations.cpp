class Solution {
public:

    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int mSum = 0, nSum = 0; 
        int m = rolls.size();
        float mMean = 0.00, nMean = 0.00; 
        for(auto &roll:  rolls){
            mSum += roll;
        }
        mMean = mSum / m;
        nSum = mean * (m + n) - mSum;

        if(nSum > 6 * n || nSum < 1 * n){
            return {};
        }
        else{
            int nMeanLow = nSum / n;
            cout << nMeanLow << endl;
            vector<int> ans (n, nMeanLow);
            for(int i = 0; i < nSum - nMeanLow * n; ++i){
                ans[i]++;
            }
            return ans;
        }
    }
};