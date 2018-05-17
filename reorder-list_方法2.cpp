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
    void reorderList(ListNode *head) {
        if(head == NULL)
            return;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *pre = slow->next;
        if(pre != NULL && pre->next != NULL){
            ListNode *nex = pre->next;
            while(nex != NULL){
                pre->next = nex->next;
                nex->next = slow->next;
                slow->next = nex;
                nex = pre->next;
            }
        }
        merge(head, slow);
    }
    
    void merge(ListNode *head, ListNode *slow){
        ListNode *p = head;
        ListNode *q = slow->next;
        while(q != NULL && p != NULL){
            slow->next = q->next;
            q->next = p->next;
            p->next = q;
            q = slow->next;
            p = p->next->next;
        }
    }
};
