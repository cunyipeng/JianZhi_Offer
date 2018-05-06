#include<stdio.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


void SelectionSort(int A[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        int min = i;
        for(int j = i + 1; j < n; ++j)
        {
            if(A[j] < A[min])
                min = j;
        }
        if(i != min)
            Swap(A[min], A[i]);
    }
}




int main()
{
    int A[] = { 6, 5, 1, 1, 8, 7, 2, 4 };    // 从小到大冒泡排序
    int n = sizeof(A) / sizeof(int);
    SelectionSort(A, n);
    printf("排序结果：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}


