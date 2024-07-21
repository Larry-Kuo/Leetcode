class Solution {
public:
    void dfs(TreeNode* root, vector<int>& path, vector<vector<int>>& leafPaths, int& n) {
        if (!root) {
            return;
        }

        path.push_back(n);
        n++;

        if (!root->left && !root->right) {
            leafPaths.push_back(path);
        } else {
            if (root->left) {
                dfs(root->left, path, leafPaths, n);
            }
            if (root->right) {
                dfs(root->right, path, leafPaths, n);
            }
        }

        path.pop_back();
    }

    int countPairs(TreeNode* root, int distance) {
        int n = 0;
        int sum = 0;
        vector<int> path;
        vector<vector<int>> leafPaths;

        dfs(root, path, leafPaths, n);

        for (int i = 0; i < leafPaths.size() - 1; ++i) {
            for (int j = i + 1; j < leafPaths.size(); ++j) {
                int same = 0;
                while (same < leafPaths[i].size() && same < leafPaths[j].size() && leafPaths[i][same] == leafPaths[j][same]) {
                    same++;
                }
                int d = (leafPaths[i].size() - same) + (leafPaths[j].size() - same);
                if (d <= distance) {
                    sum++;
                }
            }
        }

        return sum;
    }
};