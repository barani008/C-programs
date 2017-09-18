/**
Given a singly linked list L: L0?L1?…?Ln-1?Ln,
reorder it to: L0?Ln?L1?Ln-1?L2?Ln-2?…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==NULL || head->next == NULL){
            return;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *h2 = slow->next;
        slow->next = NULL;
        h2 = reverseNode(h2);
        fast = head;
        while(fast != NULL && h2!=NULL){
            ListNode* tmp = fast->next;
            fast->next = h2;
            h2 = h2->next;
            fast = fast->next;
            fast->next = tmp;
            fast = fast->next;
        }
    }
    
    ListNode* reverseNode(ListNode* head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur!=NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};