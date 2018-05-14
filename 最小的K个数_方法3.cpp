// 时间复杂度O(nlogk)
class Solution {
public:
    typedef multiset<int, greater<int>> intSet;
    typedef multiset<int, greater<int>>::iterator setIterator;
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        intSet num;
        
        if(input.size() < k || k < 1)
            return res;
        
        for(int i = 0; i < input.size(); i++){
            if(num.size() < k)
                num.insert(input[i]);
            else
            {
                setIterator iterGreatest = num.begin();
                
                if(input[i] < *(iterGreatest))
                {
                    num.erase(iterGreatest);
                    num.insert(input[i]);
                }
            }
        }
        for(setIterator i = num.begin(); i != num.end(); i++)
        {
             res.insert(res.begin(), *i);
        }
        return res;
    }
};
