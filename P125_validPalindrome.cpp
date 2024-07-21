class Solution {
public:
    bool isPalindrome(string s) {
        auto l = s.begin();
        auto r = s.end()-1;
        while(l<r){
            if(!isalnum(*l)){
                l++;
                continue;
            }
            else if(!isalnum(*r)){
                r--;
                continue;
            }
            else if(tolower(*l)!=tolower(*r)){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};