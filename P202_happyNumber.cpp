class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n!=1){
            int num = 0;
            while(n>0){
                num += (n%10)*(n%10);
                n /= 10;
            }
            if(set.count(num)){
                return false;
            }
            else{
                set.insert(num);
            }
            n = num;
        }
        return true;
    }
};