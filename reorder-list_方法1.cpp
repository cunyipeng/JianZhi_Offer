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
        ListNode *rear = head;
        ListNode *tmp;
        while(head != NULL && head->next != NULL){
            while(rear->next->next != NULL)
                rear = rear->next;
            tmp = rear->next;
            rear->next = NULL;
            tmp->next = head->next;
            head->next = tmp;
            head = rear = tmp->next;
        }
    }
};
