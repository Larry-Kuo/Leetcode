class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for(int sold = 0; sold < n; ++sold){
            int l = 0; 
            int r = n - 1;
            int leftGreater = 0, leftSmaller = 0;
            int rightGreater = 0, rightSmaller = 0;
            while(l < sold){
                if(rating[l] < rating[sold]){
                    leftSmaller++;
                }
                else if(rating[l] > rating[sold]){
                    leftGreater++;
                }
                l++;
            }
            while(r > sold){
                if(rating[r] < rating[sold]){
                    rightSmaller++;
                }
                else if(rating[r] > rating[sold]){
                    rightGreater++;
                }
                r--;
            }
            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }
        return ans;
    }
};