/**
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL || k==0)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;        
        int i = 0;
        while(fast!=NULL){
            fast = fast->next;
            i++;
        }
        if(i<=k){
            k = k%i;
            if(k==0)
                return head;
        }
        fast = head;
        for(int i=0;i<k;i++){
            fast = fast->next;
        }        
        while(fast->next!=NULL){            
            fast = fast->next;
            slow = slow->next;            
        }
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};