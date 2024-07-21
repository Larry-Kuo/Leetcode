/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool traverse(TreeNode* root, int value, string &s){
        if(root->val==value){
            return true;
        }
        if(root->left&&traverse(root->left, value, s)){
            s.push_back('L');
        }
        else if(root->right&&traverse(root->right, value, s)){
            s.push_back('R');
        }
        return !s.empty();
    } 
    string getDirections(TreeNode* root, int start, int dest) {
        string startPath = "";
        string destPath = "";
        string ans = "";

        traverse(root, start, startPath);
        traverse(root, dest, destPath);

        reverse(startPath.begin(), startPath.end());
        reverse(destPath.begin(), destPath.end());

        auto sit = startPath.begin();
        auto dit = destPath.begin();
        while(!startPath.empty()&&!destPath.empty()&&*sit==*dit){
            sit++;
            dit++;
        }
        startPath.erase(startPath.begin(), sit);
        destPath.erase(destPath.begin(), dit);
        for(int i=0; i<startPath.length(); ++i){
            ans.push_back('U');
        }
        ans+=destPath;
        return ans;
    }
};