/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

class Solution {
public:
    int count = 0;
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if(root != NULL){
            TreeNode* node = KthNode(root->left, k);
            if(node!=NULL)
               return node;
            count++;
            if(count == k)
               return root;
            node = KthNode(root->right, k);
            if(node!=NULL)
               return node;
        }
        return NULL;
    }
};
