/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        while(l1!=NULL && l2!=NULL){
            if(l1->val > l2->val){
                pre->next = l2;
                l2 = l2->next;
                pre = pre->next;
            }else{
                pre->next = l1;
                l1 = l1->next;
                pre = pre->next;
            }
        }
        if(l1==NULL && l2!=NULL)
            pre->next = l2;
        else if(l2==NULL && l1!=NULL)
            pre->next = l1;
        return preHead->next;
    }
};