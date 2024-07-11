class Solution {
public:
    int convert(char c){
        return c - 'a';
    }
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vec(26, 0);
        for(int i=0; i<magazine.length(); ++i){
            vec[convert(magazine[i])]++;
        }
        for(int i=0; i<ransomNote.length(); ++i){
            vec[convert(ransomNote[i])]--;
            if(vec[convert(ransomNote[i])]<0){
                return false;
            }
        }
        return true;
    }
};