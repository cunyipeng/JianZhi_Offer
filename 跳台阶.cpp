/*
class Solution {
public:
    int jumpFloor(int number) {
        if(number<=0)
            return -1;
        else if(number==1)
            return 1;
        else if(number==2)
            return 2;
        else
            return jumpFloor(number-1)+jumpFloor(number-2);
    }
};
*/

class Solution {
public:
    int jumpFloor(int n) {
        int f = 1;
        int g = 2;
        while(--n){
            g += f;
            f = g - f;
        }
        return f;
    }
};


/*dp是全局数组，大小为n, 全部初始化为0，是题目中的动态规划表*/  
int fun(int n){  
    if (n==1||n==2)  
        return n;  
    /*判断n-1的状态有没有被计算过*/  
    if (!dp[n-1])  
        dp[n-1] = fun(n-1);  
    if(!dp[n-2])  
        dp[n-2]=fun(n-2);  
    return dp[n-1]+dp[n-2];  
}  
