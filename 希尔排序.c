#include<stdio.h>

void Show(int arr[], int n);
void ShellSort(int arr[], int n);

int main()
{
    int arr_test[10] = {49,38,65,97,76,13,27,48,55,4};
    Show(arr_test, 10);
    ShellSort(arr_test, 10);
    Show(arr_test, 10);
    return 0;
}

void Show(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void ShellSort(int arr[], int n)
{
    int i,j,k;
    int temp, gap;
    for(gap=n/2; gap>0; gap/=2)
    {
        for(i=0; i<gap; i++)
        {
            for(j=i+gap; j<n; j+=gap)
                if(arr[j] < arr[j-gap])
               {
                   temp = arr[j];
                   k = j - gap;
                   while(k>=0 && arr[k] > temp)
                   {
                       arr[k+gap] = arr[k];
                       k -= gap;
                   }
                   arr[k+gap] = temp;
               }
        }
    }
}
