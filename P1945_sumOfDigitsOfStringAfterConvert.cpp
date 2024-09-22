class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> vec;
        int sum = 0;
        for(auto &c: s){
            int convert = c - 'a' + 1;
            if(convert >= 10){
                vec.push_back(convert % 10);
                convert /= 10;
            }
            vec.push_back(convert);
        }
        for(int i = 0; i < k; ++i){
            if(i != 0){
                vec.clear();
                //turn sum into vector of digits
                while(sum > 0){
                    vec.push_back(sum % 10);
                    sum /= 10;
                }
            }
            sum = 0;
            for(auto digit: vec){
                sum += digit;
            }
        }
        return sum;
    }
};