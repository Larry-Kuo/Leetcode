/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    void traverse(Node* root){
        if(!root)   return;
        for(auto &node:  root->children){
            traverse(node);
        }
        ans.push_back(root->val);
        return;
    }
    vector<int> postorder(Node* root) {
        traverse(root);
        return ans;

    }
};