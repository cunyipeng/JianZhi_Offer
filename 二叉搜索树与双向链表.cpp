/*
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
    TreeNode* head = NULL;
    TreeNode* realHead = NULL;
    void SubConvert(TreeNode* root){
        if(root == NULL) return;
        SubConvert(root->left);
        if(head == NULL){
            realHead = root;
            head = root;
        }else{
            head->right = root;
            root->left = head;
            head = root;
        }
        SubConvert(root->right);
    }
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        SubConvert(pRootOfTree);
        return realHead;
    }
};
