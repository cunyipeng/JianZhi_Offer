// 时间复杂度O(nk)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.size() == 0 || input.size() < k)
            return res;
        for(int i  = 0; i < k; i++)
        {
             for(int j = 0; j < input.size() - i - 1; j++)
             {
                if(input[j] < input[j+1])
                {
                     int temp = input[j+1];
                     input[j+1] = input[j];
                     input[j] = temp;
                }
             }
             res.push_back(input[input.size() - i - 1]);
        }
        return res;
    }
};


