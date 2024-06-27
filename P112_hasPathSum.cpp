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
    bool DFS(TreeNode* root, int targetSum, int sum){
        sum+=root->val;
        if(!root->left&&!root->right){
            if(sum==targetSum){  
                return true;
            }
            else{
                return false;
            }
        }
        if(root->left)  {
            if(DFS(root->left, targetSum, sum))  return true;
        }
        if(root->right) {
            if(DFS(root->right, targetSum, sum)) return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if(!root)   return false;
        return DFS(root, targetSum, sum);
    }
};