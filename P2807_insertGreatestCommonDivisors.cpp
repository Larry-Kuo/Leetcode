class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ptr = head;
        while(ptr->next){
            int GCD = gcd(ptr->val, (ptr->next)->val);
            ListNode* tmp = new ListNode (GCD);
            tmp->next = ptr->next;
            ptr->next = tmp;
            ptr = tmp->next;
        }
        return head;
    }
};