int Width(Node* root)
    {
        queue<Node*> q;
        if (root)
            q.push(root);
        int maxwidth = 1;
        while (!q.empty())    
        {
            int length = q.size();
            while (length-- > 0)    
            {
                Node* front = q.front();
                q.pop();
                if (front->_left)
                {
                    q.push(front->_left);
                }
                if (front->_right)
                {
                    q.push(front->_right);
                }
            }
            maxwidth = maxwidth > q.size() ? maxwidth : q.size();
        }
        return maxwidth;
    }
