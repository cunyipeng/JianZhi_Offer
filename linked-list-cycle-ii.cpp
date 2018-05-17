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
    ListNode *detectCycle(ListNode *pHead) {
        if(pHead == NULL|| pHead->next == NULL|| pHead->next->next == NULL)
            return NULL;
 
        ListNode* fast = pHead->next->next;
 
        ListNode* slow = pHead->next;
 
        /////先判断有没有环
 
        while(fast != slow){
 
            if(fast->next != NULL && fast->next->next != NULL){
 
                fast = fast->next->next;
 
                slow = slow->next;
 
            }else{
 
                //没有环,返回
 
                return NULL;
 
            }
 
        }
 
        //循环出来的话就是有环，且此时fast==slow.
 
        fast = pHead;
 
        while(fast != slow){
 
            fast = fast->next;
 
            slow = slow->next;
 
        }
 
        return slow;
    }
};
