class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int ans = 0;
        int dir = 0;
        int xmax = 0, ymax = 0;
        pair<int, int> pos = {0, 0};
        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> boxes;
        for(auto &box: obstacles){
            boxes.insert({box[0], box[1]});
        }

        for(auto &comm: commands){
            cout << pos.first << " " << pos.second << endl;
            if(comm == -1){
                if(dir == 3)    dir = 0;
                else dir++;
            }
            else if(comm == -2){
                if(dir == 0)    dir = 3;
                else dir--;
            }
            else{
                for(int i = 0; i < comm; ++i){
                    pair<int, int> expect = {pos.first + direction[dir].first,pos.second + direction[dir].second};
                    if(boxes.find({expect.first, expect.second}) != boxes.end())
                    {
                        break;
                    }
                    else{
                        pos = {pos.first + direction[dir].first, pos.second + direction[dir].second};
                        int d = pos.first * pos.first + pos.second * pos.second;
                        ans = max(ans, d);
                    }

                }
            }
        }
        return ans;
    }
};