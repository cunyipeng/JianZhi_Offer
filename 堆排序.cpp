#include<stdio.h>

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

void Heapify(int A[], int i, int size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(A[left] > A[max] && left < size)
    {
        max = left;
    }
    if(A[right] > A[max] && right < size)
    {
        max = right;
    }
    if(max != i)
    {
        Swap(A[i], A[max]);
        Heapify(A, max, size);
    }
}

int BuildHeap(int A[], int n)
{
    int heap_size = n;
    for(int i = heap_size / 2 - 1; i>=0; --i)
    {
        Heapify(A, i, n);
    }
    return heap_size;
}

void HeapSort(int A[], int n)
{
    int heap_size = BuildHeap(A, n);
    while(heap_size > 1)
    {
        Swap(A[0], A[--heap_size]);
        Heapify(A, 0, heap_size);
    }
}

int main()
{
    int a[] = {2, 5, 6, 7, 4, 1, 3, 8 ,9};
    int n = sizeof(a) / sizeof(int);
    HeapSort(a, n);
    printf("排序结果: ");
    for(int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
