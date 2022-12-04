#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static unsigned int b[10000];
void swap(int *x, int *y)
{
    int temp=*x;
          *x=*y;
          *y=temp;
}
long partition(int arr[], long low, long high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for( int j = low; j <= high - 1; j++ )
    {
            if(arr[j]< pivot)
            {
                i++;    
                if(i!=j)
                {
                    swap(&arr[i],&arr[j]);
                }
            }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i+1);
}

void quickSort(int arr[], long low, long high)
{
    if(low < high)
    {
        long pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr,pivotIndex+1, high);
    }
}

int don_cho(int a[],int k,int n)
{
    for (int i=k;i<n-1;i++)
       a[i]=a[i+1];
    n--;
    return n;
}
int khu_so_giong_nhau(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        while ((a[i]==a[i+1]) &&(i<n-1))
        {
           n= don_cho(a,i,n);

        }
    }
  return n;
}
int main()
{
    FILE *input, *output1,*output2;
    static unsigned int a[10000];
    unsigned int num;
    long n=0;
    if((input=fopen("input.txt","r")) == NULL)
    {
        printf("Loi! khong mo duoc file");
        exit(1);
    }
    output1=fopen("output.txt","w");
    printf("\n");
    while (fscanf(input,"%d", &num)!=EOF)
    {
        a[n]=num;
        n++;
    }
    fclose(input);
    printf("So phan tu:%ld\n",n);
    printf("day so sau sap xep:\n");
    fprintf(output1,"day so sau sap xep:\n");
    quickSort(a,0,n-1);
    for (int i=0; i<n;i++)
    {
        fprintf(output1,"%8d",a[i]);
        printf("%8d",a[i]);
    }
    fclose(output1);
    output2=fopen("output2.txt","w");
    printf("\n");
    printf("\n Day so sau sap xep va khu so giong nhau:\n");
    fprintf(output2,"Day so sau sap xep va khu so giong nhau:\n");
     n=khu_so_giong_nhau(a,n);
     for (int i=0; i<n;i++)
    {
        fprintf(output2,"%8d",a[i]);
        printf("%8d",a[i]);
    }
    fclose(output2);
  return 0;
}