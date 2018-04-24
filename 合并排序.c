#include<stdio.h>

void mergeSort(int [], int [], int, int);
void merge(int[], int[], int, int, int);

int main()
{
    int Num=0;
    int iDatas[10000];
    int Buffer[10000];
    scanf("%d",&Num);
    while(Num!=-1)
    {
        for(int i=0;i<Num;i++) scanf("%d", &iDatas[i]);
        mergeSort(iDatas, Buffer, 0, Num-1);
        for(int i=0;i<Num;i++) printf("%d ", iDatas[i]);
        printf("\r\n");
        scanf("%d",&Num);
    }
    return 0;
}

void mergeSort(int iDatas[], int Buffer[], int iLow, int iHigh)
{
    if(iLow<iHigh)
    {
        int iMid = (iLow+iHigh)/2;
        mergeSort(iDatas, Buffer, iLow, iMid);
        mergeSort(iDatas, Buffer, iMid+1, iHigh);
        merge(iDatas, Buffer, iLow, iMid, iHigh);
        for(int i=iLow;i<=iHigh;i++)
            iDatas[i] = Buffer[i];
    }
}

void merge(int iDatas[], int Buffer[], int iLow, int iMid, int iHigh)
{
    int i=iLow,j=iMid+1,k=iLow;
    while((i<=iMid)&&(j<=iHigh))
    {
        if(iDatas[i]<=iDatas[j])
            Buffer[k++] = iDatas[i++];
        else
            Buffer[k++] = iDatas[j++];
    }

    if(i<=iMid)
        for(int ii=i;ii<=iMid;ii++) Buffer[k++]=iDatas[ii];
    else
        for(int jj=j;jj<=iHigh;jj++) Buffer[k++]=iDatas[jj];
}
