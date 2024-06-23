class Solution {
public:
    int numberOfSubarrays(vector<int>& vec, int k) {
        int n = vec.size();
        int l = 0;
        int r = 0;
        int niceArrays = 0;
        int oddCount = 0;
        int leftCount = 1;
        for (r = 0; r < n; ++r){
            if(vec[r]%2==0){
                if(oddCount==k){
                    niceArrays += leftCount;
                }
            }
            else{
                oddCount++;
                leftCount = (vec[l]%2==1)?0:1;
                if(oddCount>k){
                    while(l<n){
                        l++;
                        leftCount++;
                        if(vec[l]%2==1){
                            oddCount--;
                            break;
                        }
                    }
                    niceArrays += leftCount;
                }
                else if(oddCount==k){
                    while(vec[l]%2==0&&l<n){
                        l++;
                        leftCount++;
                    }
                    if(l==0)
                        leftCount++;
                    niceArrays += leftCount;
                }
            }
        }
        return niceArrays;
    }
};