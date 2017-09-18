/**
Sort a linked list using insertion sort.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* preHead = new ListNode(-1);
        ListNode* pre = preHead;
        ListNode* cur = head;
        while(cur!=NULL){
            pre = preHead;
            ListNode* tmp = preHead->next;
            while(tmp!=NULL && tmp->val < cur->val){
                pre = tmp;
                tmp = tmp->next;
            }
            pre->next = cur;
            cur = cur->next;
            pre->next->next = tmp;
        }
        return preHead->next;
    }
};