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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty()) return nullptr;

        auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };

        priority_queue<ListNode*,vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(int i=0; i<lists.size(); i++){
            pq.push(lists[i]);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            temp->next = node;
            temp=temp->next;
            node= node->next;
            if(node != nullptr){
                pq.push(node);
            }
        }

        return dummy->next;
    }
};
