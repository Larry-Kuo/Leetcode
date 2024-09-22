class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        //count node length
        int length = 0;
        ListNode* ptr = head;
        while(ptr){
            length++;
            ptr = ptr->next;
        }
        //determine the size of each chunks
        int ksize = length / k;
        int krem = length % k;
        vector<int> chunks (k, ksize);
        for(int i = 0; i < krem; ++i){
            chunks[i]++;
        }
        //start splitting nodes
        ptr = head;
        for(int i = 0; i < k; ++i){
            ListNode* tmp = nullptr;
            ListNode* end = nullptr;
            for(int j = 0; j < chunks[i]; ++j){
                if(!ptr)    break;
                if(!tmp){
                    //the start of each chunks
                    tmp = ptr;
                    end = ptr;
                }
                else{
                    end->next = ptr;
                    end = end->next;
                }
                ptr = ptr->next;
            }
            //sever the end of each chunks
            if(end) end->next = nullptr;
            ans.push_back(tmp);
        }
        return ans;
    }
};