class Solution {
public:
    int minimumPushes(string word) {
        vector<int> vec (26, 0);
        int ans = 0;
        for(auto &it: word){
            vec[it-'a']++ ;
        }

        sort(vec.rbegin(), vec.rend());

        for(int i = 0; i < 26; ++i){
            if(i < 8){
                ans += vec[i];
            }
            else if(i < 16){
                ans += 2 * vec[i];
            }
            else if(i < 24){
                ans += 3 * vec[i];
            }
            else{
                ans += 4 * vec[i];
            }
        }

        return ans;

    }
};