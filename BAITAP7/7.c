#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void shakersort(int a[],int n)
{
    int left = 0;
    int right = n-1;
    while(left < right)
    {
        for(int i = left;i < right; i++)
        if(a[i] > a[i+1])
            swap(&a[i], &a[i+1]);
        right--;
        for(int i = right; i > left; i--)
            if(a[i] < a[i-1])
            swap(&a[i], &a[i-1]);
            left++;
    }
}
int main()
{
    FILE *input, *output;
    int a[100];
    int num=0;
    int n=0;
    if((input=fopen("input.txt","r")) == NULL)
    {
        printf("Loi! khong mo duoc file");
        exit(1);
    }
    output=fopen("output.txt","w");
    while (fscanf(input,"%d", &num)!=EOF)
    {
        a[n]=num;
        n++;
    }
    fclose(input);
     printf("\nSo phan tu:%ld\n",n);
     printf("\nDay so sau sap xep\n");
    shakersort(a,n);
    for (int i=0; i<n;i++)
    {
        printf("%8d",a[i]);
    }
    int k, x, y, i, demTong=0, demHieu=0;
    printf("\n Nhap vao so can tim k: ");scanf("%d",&k);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
          {
              if(a[i]+a[j]==k)
              {
                  demTong++;
              }
              else if(a[i]-a[j]==k)
              {
                  demHieu++;
              }
              else if(a[j]-a[i]==k)
              {
                  demHieu++;
              }
          }
    }
    printf("k= %d\n",k);
    fprintf(output,"So k : %d\n",k);
    printf("Co %d cap so co tong bang k \n",demTong);
    fprintf(output,"So luong cap so co tong bang k: %d\n",demTong);
    printf("Co %d cap so co hieu bang k \n",demHieu);
    fprintf(output,"So luong cap so co hieu bang k: %d\n",demHieu);
    fclose(output);
}