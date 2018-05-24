/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode *cur = head;
        while(cur != NULL){
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        cur = head;
        while(cur != NULL){
            if(cur->random != NULL)
               cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        RandomListNode *pHead = head->next;
        RandomListNode *p = pHead;
        cur = head;
        while(cur != NULL){
            cur->next = cur->next->next;
            if(p->next != NULL)
                p->next = p->next->next;
            cur = cur->next;
            p = p->next;
        }
        return pHead;
    }
};
