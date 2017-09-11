/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        preHead->next = head;
        ListNode* cur = head;
        ListNode* next = head->next;
        ListNode* rem_val = NULL;
        while(cur !=NULL && next!=NULL){
            if(cur->val == next->val){
                pre->next = next->next;
                rem_val = cur;
                cur = next->next;
                if(next->next!=NULL){
                    next = next->next->next;
                }
            }else if(rem_val!=NULL && rem_val->val == cur->val){
                pre->next = next;
                cur = next;
                next = next->next;
            }else{
                pre = cur;
                cur = next;
                next = next->next;
            }
        }
        if(cur!=NULL && rem_val!=NULL && rem_val->val == cur->val){
            pre->next = cur->next;
        }
        return preHead->next;
    }
};