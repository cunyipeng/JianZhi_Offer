/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL || k==0)
            return NULL;
        ListNode* pFirst;
        ListNode* pLast;
        pFirst = pListHead;
        k--;
        while(k--){
            if(pListHead->next==NULL)
                return NULL;
            else
                pListHead = pListHead->next;
        }
        pLast = pListHead;
        while(pLast->next!=NULL){
            pLast = pLast->next;
            pFirst = pFirst->next;
        }
        return pFirst;
    }
};
