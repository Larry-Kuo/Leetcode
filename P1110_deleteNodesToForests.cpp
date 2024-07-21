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
    void traverse(TreeNode* &root, vector<TreeNode*> &vec, bool toDelete[1001]){
        if(!root){
            return;
        }
        if(root->left){
            traverse(root->left, vec, toDelete);
        }
        if(root->right){
            traverse(root->right, vec, toDelete);
        }
        if(toDelete[root->val]==true){
            if(!root->left&&!root->right){
                //deleting leaf
                root = nullptr;
                delete root;
            }
            else{
                if(root->left){
                    vec.push_back(root->left);
                }
                if(root->right){
                    vec.push_back(root->right);
                }
                root = nullptr;
                delete root;
            }
        }
        return;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        bool toDelete[1001] = {};
        for(auto &it: to_delete){
            toDelete[it] = true;
        }
        traverse(root, ans, toDelete);
        if (root && !toDelete[root->val]) {
            ans.push_back(root);
        }
        return ans;  
    }
};