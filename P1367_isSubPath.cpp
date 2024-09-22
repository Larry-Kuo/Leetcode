class Solution {
public:
    bool flag = false;
    void helper(ListNode* head, TreeNode* root){
        if(!head || !root)  return;
        if(head->val == root->val){
            if(head->next == nullptr){
                //already check the whole list
                flag = true;
                return;
            }
            helper(head->next, root->left);
            helper(head->next, root->right);
        }
        return;
    }
    void traverse(ListNode* head, TreeNode* root){
        //traverse all the nodes with the value same as the head of list
        if(!head || !root)  return;
        if(head->val == root->val){
            helper(head, root);
        }
        traverse(head, root->left);
        traverse(head, root->right);
        return;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        traverse(head, root);
        return flag ? true : false;
    }
};