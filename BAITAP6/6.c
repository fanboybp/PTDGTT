#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
static unsigned int b[1000000];
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
long partition (int arr[], long low, long high)
{
    int pivot = arr[high];
    int i = (low-1);
    for(int j = low ; j <= high-1 ; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            if(i != j)
            {
                swap(&arr[i], &arr[j]);
            }
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}
void quicksort(int arr[], long low, long high)
{
    if (low < high)
    {
        long pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex-1);
        quicksort(arr, pivotIndex+1, high);
    }
}
int main()
{
    FILE *input, *output;
    static unsigned int a[1000000];
    unsigned int num;
    long n=0;
    if((input = fopen("input.txt","r")) == NULL)
    {
        printf("Loi! khong mo duoc file");
        exit(1);
    }
    output = fopen("output.txt","w");
    while (fscanf(input,"%d", &num)!=EOF)
    {
        a[n] = num;
        n++;
    }
    fclose(input);
     printf("\nSo phan tu:%ld\n",n);
     printf("\nDay so sau sap xep\n");
     fprintf(output,"\nDay so sau sap xep\n");
    quicksort(a,0,n);
    for (int i=0; i<n;i++)
    {
        printf("%8d",a[i]);
        fprintf(output,"%8d",a[i]);

    }
    int k, x, y, i, dem1=0, dem2=0;
    printf("\n Nhap vao so can tim K: ");
    scanf("%d", &k);
    printf("Nhap vao so x va y: ");
    scanf("%d%d", &x, &y);
    for ( i=0; i<n; i++)
    {
        if (a[i] == k)
            dem1++;
        if ((a[i] > x) && (a[i] < y))
            dem2++;
    }
    printf("So k= %d\n",k);
    fprintf(output,"So k= %d\n",k);
    printf("So phan tu bang %d co:%d\n",k,dem1);
    fprintf(output,"So phan tu bang %d co:%d\n",k,dem1);
    printf("x= %d\n",x);
    fprintf(output,"x= %d\n",x);
    printf("y= %d\n",y);
    fprintf(output,"y= %d\n",y);
    printf("So phan tu lon hon %d va nho hon %d co:%d\n",x,y,dem2);
    fprintf(output,"So phan tu lon hon %d va nho hon %d co:%d\n",x,y,dem2);
    fclose(output);
}
