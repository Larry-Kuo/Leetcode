class Solution {
public:

    void islands(vector<vector<char>>& grid, vector<vector <bool>> &vis, pair<int, int> coor){
        int x = coor.first;
        int y = coor.second;
        if(grid[y][x] == '0'||vis[y][x])
            return;
        else {
            vis[y][x] = true;
            if(x-1>=0){
                islands(grid, vis, {x-1, y});
            }
            if(x+1<grid[0].size()){
                islands(grid, vis, {x+1, y});
            }
            if(y-1>=0){
                islands(grid, vis, {x, y-1});
            }
            if(y+1<grid.size()){
                islands(grid, vis, {x, y+1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int setCnt = 0;
        int nx = grid[0].size();
        int ny = grid.size();
        vector<vector<bool>> vis (ny, vector <bool>(nx, false));
        for (int y = 0; y < ny; ++y)
        {
            for (int x = 0; x < nx; ++x)
            {   
                if(vis[y][x] || grid[y][x]== '0')
                    continue;
                islands(grid, vis, {x, y});
                setCnt++;
            }
        }
        return setCnt;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();