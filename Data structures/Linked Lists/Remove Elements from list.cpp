/**
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return NULL;
        ListNode* preHead = new ListNode(val+1);
        ListNode* pre = preHead;
        ListNode* cur = head;
        while(cur!=NULL){
            if(cur->val!= val){
                pre->next = cur;
                pre = cur;
            }
            cur = cur->next;
        }
        if(pre->next!=NULL && pre->next->val == val){
            pre->next = NULL;
        }
        return preHead->next;
    }
};