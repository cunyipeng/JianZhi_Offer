bool IsComplateTree(Node* root)
{
        queue<Node*> q;
        if (root)
        {
            q.push(root);  //先将节点压入队列中
        }
        //这里给一个tag是标记是否出现非满节点
        bool tag = true;
        while (!q.empty())
        {
            Node* front = q.front();  
            q.pop();
            //如果已经出现过非满结点，则后面再出现有孩子的结点则一定不是完全二叉树。
            if (front->_left)
            {
                if (tag == false)
                {
                    return false;
                }
                q.push(front->_left);
            }
            else {
                tag = false;
            }
            if (front->_right)
            {
                if (tag == false)
                {
                    return false;
                }
                q.push(front->_right);
            }
            else {
                tag = false;
            }
        }
        return true;
 }
