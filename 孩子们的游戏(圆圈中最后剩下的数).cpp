class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        unsigned int i = 0;
        list<int> num;
        for(i = 0; i < n; ++i)
            num.push_back(i);
        list<int>::iterator cur = num.begin();
        while(num.size() > 1)
        {
            for(int i = 1; i < m; ++i)
            {
                cur++;
                if(cur == num.end())
                    cur = num.begin();
            }
            list<int>::iterator next = ++cur;
            if(next == num.end())
                next = num.begin();
            --cur;
            num.erase(cur);
            cur = next;
        }
        return *(cur);
    }
};
