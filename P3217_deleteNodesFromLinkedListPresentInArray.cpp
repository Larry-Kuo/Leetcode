class Solution {
public:
    
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> numset (nums.begin(), nums.end());
        if(head->next == nullptr){
            //at least one element is not to be deleted
            return head;
        }

        while(numset.find(head->val) != numset.end()){
            //check if the first element needs to be deleted
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode* prev = head;
        ListNode* node = head->next;

        while(node){
            if(numset.find(node->val) != numset.end()){
                //needs to be deleted
                if(node->next){
                    prev->next = node->next;
                    delete node;
                    node = prev->next;
                }
                else{
                    //when the node to be deledted is the last element
                    prev->next = nullptr;
                    delete node;
                    node = nullptr;
                }
            }
            else{
                node = node->next;
                prev = prev->next;
            }
        }
        return head;
    }
};