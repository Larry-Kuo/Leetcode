class Solution {
public:
    int passThePillow(int n, int time) {
        int cnt = time / (n-1);
        int r = time % (n-1);
        if((cnt&1)==0){
            return 1+r;
        }
        else{
            return n-r;
        }
    }
};