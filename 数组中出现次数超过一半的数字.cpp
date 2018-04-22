/*
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n == 0)
            return 0;
        int count = 1;
        int num = numbers[0];
        for(int i = 1; i < n; i++){
            if(numbers[i] == num) 
                count++;
            else
                count--;
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        count = 0;
        for(int i = 0; i < n; i++){
            if(numbers[i] == num) 
                count++;
        }
        if(count * 2 > n)
            return num;
        return 0;
    }
};
*/

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n == 0)
            return 0;
        int middle = n >> 1;
        int start = 0;
        int end = n - 1;
        int index = partition(numbers, start, end);
        while(index != middle){
            if(index > middle)
            {
                end = index - 1;
                index = partition(numbers, start, end);
            }
            else
            {
                start = index + 1;
                index = partition(numbers, start, end);
            }
        }
        int result = numbers[middle];
        int count = 0;
        for(int i = 0; i < n; i++){
            if(numbers[i] == result) 
                count++;
        }
        if(count * 2 > n)
            return result;
        return 0;
    }
    int partition(vector<int> &res, int left, int right){
        srand((unsigned)time(NULL));
        int index = rand() % (right - left + 1) + left;
        swap(res[index], res[left]);
        int a = res[left];
        int i = left + 1;
        int j = right;
        while(i<=j){
            while(res[i] <= a && i <= right) i++;
            while(res[j] > a) j--;
            if(i<j){
                swap(res[i], res[j]);
                i++;
                j--;
            }
        }
        swap(res[j], res[left]);
        return j;
    }
};
