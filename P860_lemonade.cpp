class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> changes;
        changes.insert({5, 0});
        changes.insert({10, 0});
        for(auto& it: bills){
            switch(it){
                case 5:
                    changes[5]++;
                    break;
                case 10:
                    if(changes[5] > 0){
                        changes[5]--;
                        changes[10]++;
                    }
                    else{
                        return false;
                    }
                    break;
                case 20:
                    if(changes[10] > 0 && changes[5] > 0){
                        changes[10]--;
                        changes[5]--;
                    }
                    else if(changes[5] >= 3){
                        changes[5] -= 3;
                    }
                    else{
                        return false;
                    }
                    break;
                default:
                    break;
            }
        }
        return true;
    }
};