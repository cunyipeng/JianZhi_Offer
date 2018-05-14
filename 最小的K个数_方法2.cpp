// 时间复杂度O(n)
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int n = input.size();
        if(n == 0 || n < k)
            return res;
        int start = 0;
        int end = n - 1;
        int index = partition(input, start, end);
        while(index != k - 1){
            if(index > k - 1)
            {
                end = index - 1;
                index = partition(input, start, end);
            }
            else
            {
                start = index + 1;
                index = partition(input, start, end);
            }
        }
        for(int i  = 0; i < k; i++)
             res.push_back(input[i]);
        return res;
    }
    
    int partition(vector<int> &res, int left, int right){
        srand((unsigned)time(NULL));
        int index = rand() % (right - left + 1) + left;
        swap(res[index], res[left]);
        int a = res[left];
        int i = left + 1;
        int j = right;
        while(i <= j){
            while(res[i] <= a && i <= right) i++;
            while(res[j] > a) j--;
            if(i < j){
                swap(res[i], res[j]);
                i++;
                j--;
            }
        }
        swap(res[j], res[left]);
        return j;
    }
};
