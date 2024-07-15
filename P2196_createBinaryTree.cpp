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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> set;
        unordered_map<int, TreeNode*> tmap;
        for(auto &it: descriptions){
            set.insert(it[0]);
        }
        for(auto &it: descriptions){
            if(set.find(it[1])!=set.end()){
                set.erase(it[1]);
            }
        }
        int rootVal = *set.begin();
        TreeNode* root = new TreeNode(rootVal);
        tmap.insert({rootVal, root});
        TreeNode* parent = NULL;
        TreeNode* child = NULL;
        for(auto &it: descriptions){
            if(tmap.find(it[0])!=tmap.end()){
                parent = tmap[it[0]];
            }
            else{
                parent = new TreeNode(it[0]);
                tmap.insert({it[0], parent});
            }
            if(tmap.find(it[1])!=tmap.end()){
                child = tmap[it[1]];
            }
            else{
                child = new TreeNode(it[1]);
                tmap.insert({it[1], child});
            }
            if(it[2]){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
        }
        return root;
    }
};