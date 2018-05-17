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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return false;
        
        ListNode *fast = head->next->next;
        ListNode *slow = head->next;
        
        while(fast != slow){
            if(fast->next != NULL && fast->next->next != NULL){
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }
};
