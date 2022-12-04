#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
static unsigned int b[100000];
void swap(int *x, int *y)
{
    int temp=*x;
        *x=*y;
        *y=temp;
}
    void heapify (int arr[], long n, long i)
{
    long largest = i;
    long left = 2 * i + 1;
    long right = 2 * i + 2;
    if((left<n) && (arr[left] > arr[largest]))   largest = left;
    if((right<n) && (arr[right] > arr[largest]))   largest = right;
    if(largest !=i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], long n)
{
    for (long k = n / 2 - 1; k>=0; k--)
        heapify(arr, n, k);
    printf("\n Making heap done");
    for( long i=n-1; i>=0;i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr,i,0);
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
    printf("Day so sau sap xep:\n");
    fprintf(output1,"Day so sau sap xep:\n");
    heapSort(a,n);
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