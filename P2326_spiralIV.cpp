class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans (m, vector<int> (n, -1));
        vector<pair<int, int>> directions {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;
        pair<int, int> pos = {0, -1};

        ListNode* ptr = head;
        while(ptr){

            pair<int, int> expect = {pos.first + directions[dir].first, pos.second + directions[dir].second};
            if(expect.first >= m || expect.second >= n || expect.first < 0 || expect.second < 0 || ans[expect.first][expect.second] != -1){
                dir = (dir + 1) % 4;
            }
            pos = {pos.first + directions[dir].first, pos.second + directions[dir].second};
            ans[pos.first][pos.second] = ptr->val;
            ptr = ptr->next;
            
        }
        return ans;
    }
};