#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
static unsigned int b[100000];
void swap(int *x, int *y)
{
    int temp=*x;
        *x=*y;
        *y=temp;
}
void Merging(int arr[],long left, long mid, long right)
{
    long left_1, left_2,i;
    left_1 = left; left_2 = mid + 1; 
    for(i = left; left_1 <= mid && left_2 <=right; i++)
    {
        if (arr[left_1] <= arr[left_2])
            b[i] = arr[left_1++];
        else
            b[i] = arr[left_2++];
    }
        while(left_1 <= mid) b[i++] = arr[left_1++];
        while(left_2 <= right) b[i++] = arr[left_2++];
        for(i = left; i <= right; i++) arr[i] = b[i];
}
void MergeSort(int arr[], int left, int right)
{
    if (left<right)
    {
        int mid = left+(right-left)/2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        Merging(arr, left, mid, right);
    }
}
void BubleSort(int a[], int n)
{
    for (long i=0; i<n-1; i++)
        for(long j=0; j<n-1-i; j++)
            if(a[j]>a[j+1])
            swap(&a[j], &a[j + 1]);
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
    printf("------------------------------------------\n");
    printf("            SAP XEP TRON         \n");
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
    MergeSort(a,0,n);
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