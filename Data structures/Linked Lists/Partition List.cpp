/**
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* cur = head;
        while(cur!=NULL && cur->val<x){
            pre = cur;
            cur = cur->next;
        }
        ListNode* head2 = cur;
        ListNode* pre2 = pre;
        while(cur!=NULL){
            if(cur->val < x){
                pre->next = cur;
                pre = cur;
                pre2->next = cur->next;
                cur = cur->next;
            }else{
                pre2 = cur;
                cur = cur->next;
            }
        }
        pre->next = head2;
        return preHead->next;
    }
};