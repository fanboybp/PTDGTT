#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
static unsigned int b[10000];
void swap(int *x,int *y)
{
    int temp;
    temp =*x;
    *x = *y;
    *y =temp;
}
void bubble_sort(int arr[], int n)
{
    for(long i=0; i<n-1; i++)
        for(long j=n-1; j> i;j--)
        if(arr[j] < arr[j-1])
             swap(&arr[j],&arr[j-1]); 
}
void ShakerSort(int arr[], int n)
{
    int L = 0;
    int R = n - 1;
    int i;
    while(L < R)
    {
        for ( i = L; i < R; i++)
            if(arr[i] > arr[i + 1])
            swap(&arr[i],&arr[i + 1]);
            R--;
        for ( i = R; i > L; i--)
            if(arr[i] < arr[i - 1])
            swap(&arr[i],&arr[i - 1]);
            L++;
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
    FILE *file_input, *file_output1,*file_output2;
    static unsigned int a[10000];
    unsigned int num;
    long n=0;
    if((file_input=fopen("input.txt","r")) == NULL)
    {
        printf("Loi! khong mo duoc file");
        exit(1);
    }
    file_output1=fopen("output.txt","w");
    printf("\n");
    while (fscanf(file_input,"%d", &num)!=EOF)
    {
        a[n]=num;
        n++;
    }
    fclose(file_input);
    printf("So phan tu:%ld\n",n);
    printf("Day so sau sap xep:\n");
    fprintf(file_output1,"Day so sau sap xep:\n");
    ShakerSort(a,n);
    bubble_sort(a,n);
    for (int i=0; i<n;i++)
    {
        fprintf(file_output1,"%8d",a[i]);
        printf("%8d",a[i]);
    }
    fclose(file_output1);
    file_output2=fopen("output2.txt","w");
    printf("\n");
    printf("\n Day so sau sap xep va khu so giong nhau:\n");
    fprintf(file_output2,"Day so sau sap xep va khu so giong nhau:\n");
     n=khu_so_giong_nhau(a,n);
     for (int i=0; i<n;i++)
    {
        fprintf(file_output2,"%8d",a[i]);
        printf("%8d",a[i]);

    }
    fclose(file_output2);
  return 0;
}