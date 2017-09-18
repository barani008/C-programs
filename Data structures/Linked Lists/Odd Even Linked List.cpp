/**

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* h1 = head;
        ListNode* c1 = head;
        ListNode* h2 = head->next;
        ListNode* c2 = head->next;
        while(c1!=NULL && c2!=NULL){
            c1->next = c2->next;
            c1 = c1->next;
            if(c1!=NULL)
                c2->next = c1->next;
            else{
                break;
            }
            c2 = c2->next;
        }
        if(c1!=NULL)
            c1->next = h2;
        else{
            c1 = h1;
            while(c1->next != NULL)
                c1 = c1->next;
            c1->next = h2;
        }
        return h1;
    }
};