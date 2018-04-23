/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int inlen = vin.size();
        if(inlen==0)
            return NULL;
        vector<int> pre_left, vin_left, pre_right, vin_right;
        TreeNode* head = new TreeNode(pre[0]);
        int gen=0;
        for(int i=0;i<inlen;i++){
            if(vin[i]==pre[0]){
                gen = i;
                break;
            }
        }
        for(int i=0;i<gen;i++){
            pre_left.push_back(pre[i+1]);
            vin_left.push_back(vin[i]);
        }
        for(int i=gen+1;i<inlen;i++){
            pre_right.push_back(pre[i]);
            vin_right.push_back(vin[i]);
        }
        head->left=reConstructBinaryTree(pre_left, vin_left);
        head->right=reConstructBinaryTree(pre_right, vin_right);
        return head;
    }
};
