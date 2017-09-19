/**

Sort a linked list in O(n log n) time using constant space complexity.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        
        ListNode* prev = NULL, *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
    
        prev->next = NULL;
    
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* preHead = new ListNode(-1);
        ListNode* cur1 = l1;
        ListNode* pre = preHead;
        ListNode* cur2 = l2;
        while(cur1!=NULL && cur2!=NULL){
            if(cur1->val < cur2->val){
                pre->next = cur1;
                pre = pre->next;
                cur1 = cur1->next;
            }else{
                pre->next = cur2;
                pre = pre->next;
                cur2 = cur2->next;                
            }
        }
        if(cur1==NULL){
            pre->next = cur2;
        }
        if(cur2==NULL){
            pre->next = cur1;
        }
        ListNode* ret = preHead->next;
        delete(preHead);
        return ret;
    }
};