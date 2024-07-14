class Solution {
struct robot{
    int idx;
    int pos;
    int hp;
    char dir;

    bool operator < (const robot& r) const
    {
        return (pos < r.pos);
    }
};
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<robot> robots;
        vector<int> ans;
        map<int, int> idx2sorted;
        int n = positions.size();
        if(n==1){
            return vector<int> {healths[0]};
        }
        for(int i =0; i< n; ++i){
            robot tmp {i, positions[i], healths[i], directions[i]};
            robots.push_back(tmp);
        } 
        sort(robots.begin(), robots.end());
        stack<int> rights; //record the idx of the robots with direction R
        for(int i=0; i<n; ++i){
            idx2sorted.insert({robots[i].idx, i});
            if(!rights.empty()&&robots[i].dir=='L'){ //collision occcured
                while(!rights.empty()&&robots[i].hp!=0){
                    if(robots[rights.top()].hp==robots[i].hp){
                        //both destroyed
                        robots[rights.top()].hp = 0;
                        robots[i].hp = 0;
                        rights.pop();
                    }
                    else if(robots[rights.top()].hp > robots[i].hp){
                        //robots in the stack survived
                        robots[rights.top()].hp--;
                        robots[i].hp = 0;
                    }
                    else{   
                        //incoming robot survived
                        robots[rights.top()].hp = 0;
                        robots[i].hp--;
                        rights.pop();
                    }
                }
            }
            else if(robots[i].dir=='R'){
                rights.push(i);
            }
        }
        
        for(int i=0; i<n; ++i){
            if(robots[idx2sorted[i]].hp>0){
                ans.push_back(robots[idx2sorted[i]].hp);
            }
        }
        return ans;
    }
};