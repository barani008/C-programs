/**
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        ListNode* cur = head;        
        while(cur!=NULL && cur->next!=NULL){
            ListNode* next = cur->next;
            ListNode* nextPair = next->next;
            next->next = cur;
            cur->next = nextPair;
            pre->next = next;
            pre = cur;
            cur = nextPair;
        }
        return preHead->next;
    }
};