class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* list = new ListNode; 
        ListNode* end = list;
        int sum = 0;
        bool addTag = true;
        while(head){
            if(head->val==0){
                if(sum!=0){
                    ListNode* node = new ListNode(sum);
                    end->next = node;
                    end = end ->next;
                    sum = 0;
                }
            }
            else{
                sum += head->val;
            }
            head = head->next;
        }
        return list->next;
    }
};