#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static unsigned int b[10000];
void swap(int *x, int *y)
{
    int temp=*x;
        *x=*y;
        *y=temp;
}void SelectionSort(int arr[], int n)
{
    int i, j, iMin;
    for ( i = 0; i < n - 1; i++)
    {
        iMin = i;
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j]<arr[iMin])
            {
               iMin = j;
            }   
        }
        swap(&arr[iMin], &arr[i]);
    }
}
void  InsertionSort(int arr[], int n)
{
    int i, j, x;
    for ( i = 1; i < n; i++)
    {
       x=arr[i];
       j=i;
       while (j>0 && arr[j-1] > x)
       {
        arr[j] = arr[j-1];
        j--;
       }
       arr[j]=x;
    }   
}
void BubleSort(int arr[], int n)
{
    for (long i=0; i<n-1; i++)
        for(long j=0; j<n-1-i; j++)
            if(arr[j]>arr[j+1])
            swap(&arr[j], &arr[j + 1]);
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
void main()
{
    printf("------------------------------------------\n");
    printf("            INSERTTION SORT VA SELECTION SORT          \n");
    printf("Writen by Nguyen Van Luan\n");
    printf("--------------------------------------------\n");
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
    SelectionSort(a,n);
    BubleSort(a,n);
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