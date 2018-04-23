#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void quickSort(int iDatas[], int left, int right);
int partition(int iDatas[], int left, int right);
void swap(int &a, int &b);

int main()
{
    int Num=0;
    int iDatas[10000];
    scanf("%d",&Num);
    while(Num!=-1)
    {
        for(int i=0;i<Num;i++) scanf("%d", &iDatas[i]);
        quickSort(iDatas, 0, Num-1);
        for(int i=0;i<Num;i++) printf("%d ", iDatas[i]);
        printf("\r\n");
        scanf("%d",&Num);
    }
    return 0;
}

void quickSort(int iDatas[], int left, int right)
{
    if(right>left)
    {
        int k = partition(iDatas, left, right);
        quickSort(iDatas, left, k-1);
        quickSort(iDatas, k+1, right);
    }
}

int partition(int iDatas[], int left, int right)
{
    srand((unsigned)time(NULL));
    int random = rand()%(right - left + 1) + left;
    swap(iDatas[random], iDatas[left]);
    int a = iDatas[left];
    int i = left + 1, j = right;
    while(i<=j)
    {
        while((iDatas[i]<=a)&&(i<=right)) i++;
        while(iDatas[j]>a) j--;
        if(i<j)
        {
            swap(iDatas[i], iDatas[j]);
            i++;
            j--;
        }
    }
    swap(iDatas[left], iDatas[j]);
    return j;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
