class Solution {
public:
    int minKBitFlips(vector<int>& vec, int k) {
        int flipCount = 0;
        int n = vec.size();
        int flips = 0;
        vector<bool> flipped(n, 0);
        for (int i = 0; i < n; ++i){
            if(i >= k){
                if(flipped[i-k])
                    flips++;
            }
            if(flips%2==1)
                vec[i] ^= 1;
            
            if(vec[i]==0){
                if(i+k >n){
                    return -1;
                }
                flips++;
                flipped[i] = true;
                flipCount++;
            }
            
        }
        return flipCount;
    }
    
};