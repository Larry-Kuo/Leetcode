class Solution {
public:
    string reverseParentheses(string s) {
        auto r = s.begin();
        auto l = r;
        while(r!=s.end()){
            if(*r!=')'){
                r++;
            }
            else{
                l = r-1;
                while(*l!='('&&l!=s.begin()){
                    l--;
                }
                reverse(l+1, r);
                r = s.erase(r)-1;
                s.erase(l);
            }
        }
        return s;
    }
};