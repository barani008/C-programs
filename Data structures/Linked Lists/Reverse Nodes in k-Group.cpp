/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* preHead = new ListNode(-1);
        preHead->next = head;
        ListNode* pre = preHead;
        ListNode* cur = head;
        ListNode* start = pre;
        int count = 0;
        while(cur!=NULL){
            cur = cur->next;
            count++;
        }
        count -= count%k;
        cur = head;
        //cout<<count<<endl;
        for(int i=0;i<count/k;i++){
            int j = 0;
            ListNode* next = cur->next;
            pre = cur;
            cur = next;
            while(j<k-1 && cur!=NULL){ 
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
                j++;
            }
            start->next->next = cur;
            ListNode* tmp = start->next;
            start->next = pre;
            start = tmp;
        }
        return preHead->next;
    }
};