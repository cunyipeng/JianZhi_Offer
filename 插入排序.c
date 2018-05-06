#include<stdio.h>

// 分类 ------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 稳定

void InsertionSort(int A[], int n)
{
    for(int i = 1; i < n; i++){
        int get = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > get)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = get;
    }
}

int main()
{
    int A[] = { 5, 5, 3, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    int n = sizeof(A) / sizeof(int);
    InsertionSort(A, n);
    printf("排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}


