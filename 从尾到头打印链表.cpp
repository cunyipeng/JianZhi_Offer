/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> value;
        if(head!=NULL)
        {
            value.insert(value.begin(),head->val);
            if(head->next!=NULL)
            {
                vector<int> temp = printListFromTailToHead(head->next);
                if(temp.size()>0)
                value.insert(value.begin(), temp.begin(), temp.end());
            }
        }
        return value;
    }
};
