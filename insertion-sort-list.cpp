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
    ListNode *insertionSortList(ListNode *head) {
        ListNode* dumy = new ListNode(INT_MIN);
        ListNode* cur = head;
        ListNode* pre = dumy;
        while (cur != NULL) {
            //保存当前节点下一个节点
            ListNode* next = cur->next;
            pre = dumy;
            //寻找当前节点正确位置的一个节点
            while (pre->next != NULL && pre->next->val < cur->val) {
                pre = pre->next;
            }
            //将当前节点加入新链表中
            cur->next = pre->next;
            pre->next = cur;
            //处理下一个节点
            cur = next;
        }
        return dumy->next;
    }
};
