bool IsCompleteTree(BinaryTreeNode *pRoot)
{
         if(pRoot == NULL)
               return false;

          queue<BinaryTreeNode*> q;
          q.push(pRoot);
          BinaryTreeNode* pCur = q.front();
          while(pCur != NULL)
          {
               q.pop();
               q.push(pCur -> left);
               q.push(pCur -> right);
               pCur = q.front();
          }

          q.pop();//把空pop出来
          //因为以经有一个空了，所以只要头不为空就不是完全二叉树
          while(! q.empty())
          {
               if(q.front() != NULL)
                    return false;
               q.pop();
          }
          return true;
}
