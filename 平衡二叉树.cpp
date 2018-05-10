class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) 
    {
        if (pRoot == NULL)
            return true;
        int left = Depth(pRoot->left);
        int right = Depth(pRoot->right);  
        return abs(right - left) < 2 && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
    
    int Depth(TreeNode* pRoot)
    {
        if(pRoot == NULL)
            return 0;
        int left = Depth(pRoot->left);
        int right = Depth(pRoot->right);
        return max(left, right) + 1;
    }
};
