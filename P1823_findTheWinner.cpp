class Solution {
public:
    int findTheWinner(int n, int k) {
        ListNode *head = new ListNode(1);
        ListNode *end = head;
        ListNode *ptr = head;
        ListNode *prev = ptr;
        int cnt = k;
        for(int i=2; i<=n; ++i){
            ListNode *node = new ListNode(i);
            end->next = node;
            end = end->next;
        }
        end->next = head;
        prev = end;
        while(ptr!=ptr->next){
            cnt--;
            if(cnt==0){
                cnt = k;
                prev->next = ptr->next;
                delete ptr;
                ptr = prev->next;
            }
            else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        return ptr->val;
    }
};