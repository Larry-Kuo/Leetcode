/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector <int> ans = {-1, -1};
        vector <int> cp;
        ListNode *r = (head->next)->next;
        ListNode *m = head->next;
        ListNode *l = head;
        int max, min = 100001;
        int location = 1;
        if(!l||!m||!r){
            return ans;
        }
        while(r){
            if((m->val<l->val&&m->val<r->val)||
            (m->val>l->val&&m->val>r->val)){
                cp.push_back(location);
            }
            location++;
            r = r->next;
            m = m->next;
            l = l->next;
        }
        if(cp.size()<2){
            return ans;
        }
        for(int i=1; i<cp.size(); ++i){
            min = std::min(min, cp[i]-cp[i-1]);
        }
        max = cp[cp.size()-1] - cp[0];
        return vector<int> {min, max};
    }
};