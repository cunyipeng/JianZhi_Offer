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
    ListNode *findMiddle(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        ListNode *tmp = new ListNode(0);
        ListNode *head = tmp;
        while(l1 != NULL && l2 != NULL){
            if(l1->val > l2->val){
                head->next = l2;
                l2 = l2->next;
            }
            else{
                head->next = l1;
                l1 = l1->next;
            }
            head = head->next;
        }
        if(l1 == NULL)
            head->next = l2;
        if(l2 == NULL)
            head->next = l1;
        return tmp->next;
    }
    
    ListNode *sortList(ListNode *head){
        if(head == NULL || head->next == NULL)
            return head;
        ListNode *mid = findMiddle(head);
        ListNode *right = sortList(mid->next);
        mid->next = NULL;
        ListNode *left = sortList(head);
        return mergeTwoList(left, right);
    }
};
