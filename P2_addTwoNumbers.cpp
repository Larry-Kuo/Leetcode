class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* ans = new ListNode;
        ListNode* tail = ans;
        int a, b;
        int com = 0;
        while(ptr1||ptr2){
            if(ptr1){
                a = ptr1->val;
                ptr1 = ptr1->next;
            }
            else{
                a = 0;
            }
            if(ptr2){
                b = ptr2->val;
                ptr2 = ptr2->next;
            }
            else{
                b = 0;
            }
            ListNode* node = new ListNode;
            node->val = (a+b+com)%10;
            if(a+b+com>=10){
                com = 1;
            }
            else{
                com = 0;
            }
            tail->next = node;
            tail = tail->next;
        }
        if(com){
            tail->next = new ListNode(1);
        }
        return ans->next;
    }
};