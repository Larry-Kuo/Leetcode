class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else if(x==0){
            return true;
        }
        else{
            vector<int> vec;
            while(x!=0){
                vec.push_back(x%10);
                x/=10;
            }
            int l = 0;
            int r = vec.size()-1;
            while(1){
                if(l==r){
                    break;
                }
                else if(l > ceil(vec.size()/2)){
                    break;
                }
                if(vec[l]!=vec[r]){
                    return false;
                }
                l++;
                r--;
            }
            return true;
        }
    }
};