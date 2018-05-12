class Solution {
    bool g_InvalidInput = false;
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)
            g_InvalidInput = true;
        
        g_InvalidInput = false;
        
        int nGreatestSum = -INT_MAX;
        int nCurSum = 0;
        for(int i = 0; i < array.size(); i++)
        {
            if(nCurSum <= 0)
                nCurSum = array[i];
            else
                nCurSum += array[i];
            
            if(nCurSum > nGreatestSum)
                nGreatestSum = nCurSum;
        }
        
        return nGreatestSum;
    }
};
