/**
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct compareList{
    bool operator()(const ListNode* l1,const ListNode* l2) const{
        return l1->val > l2->val;
    }  
    
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compareList> pq;
        ListNode* preHead = new ListNode(-1);
        ListNode* cur = preHead;
        for(ListNode* head: lists){
            if(head!=NULL)
                pq.push(head);
        }
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            if(cur->next->next!=NULL){
                pq.push(cur->next->next);
            }
            cur = cur->next;
        }
        return preHead->next;
    }
};