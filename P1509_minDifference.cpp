class Solution {
public:
    int minDifference(vector<int>& vec) {
        sort(vec.begin(), vec.end());
        int n = vec.size();
        if(vec.size()>=4){
            //take 1 element from the start
            int l0 = vec[n-4]-vec[0];
            int l1 = vec[n-3]-vec[1];
            int l2 = vec[n-2]-vec[2];
            int l3 = vec[n-1]-vec[3];
            return min({l0, l1, l2, l3});
        }
        else{
            return 0;
        }
    }
};