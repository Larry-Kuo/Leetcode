class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;
        for(auto &i: logs){
            if(i=="../"){
                if(cnt>0){
                    cnt--;
                }
            }
            else if(i=="./"){
                continue;
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};