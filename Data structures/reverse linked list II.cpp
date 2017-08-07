/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count =1;
        if(m>n || m==n)
            return head;
        if(head==NULL)
            return head;
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* start = NULL, *end = NULL;
        while(count<m && cur!=NULL){
            pre = cur;
            cur = cur->next;
            count++;
        }
        if(cur==NULL)
            return head;
        start = pre;
        end = cur;
        while(count<=n && cur!=NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        if(start!=NULL){
            start->next = pre;
            end->next = cur;
        }else{
            head = pre;
            end->next = cur;
        }
        return head;
    }
};