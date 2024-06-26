class Solution {
public:
    vector<TreeNode*> vec;
    void inorderTraverse(TreeNode* root){
        if(!root)
            return;
        if(root->left)
            inorderTraverse(root->left);
        this->vec.push_back(root);
        if(root->right)
            inorderTraverse(root->right);
    }
    TreeNode* reconstruct(int l, int r){
        if(l>r)
            return nullptr;
        int mid = l + (r - l) / 2;
        TreeNode *root = vec[mid];
        root->left = reconstruct(l, mid - 1);
        root->right = reconstruct(mid + 1, r);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return reconstruct(0, vec.size()-1);
    }
};