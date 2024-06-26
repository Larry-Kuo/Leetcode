#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int pre = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(root->right)
            bstToGst(root->right);
        pre += root->val;
        root->val = pre;
        if(root->left)
            bstToGst(root->left);
        return root;
    }
    
};

int main(){
    Solution S;
    
}