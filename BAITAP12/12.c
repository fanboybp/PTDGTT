#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    int start;
    int finish;
} lophoc ;
void Swap(lophoc *x,lophoc *y)
{
    lophoc temp = *x;
    *x = *y;
    *y = temp;
}
void ShakerSort(lophoc a[], long n)
{
    int Left = 0;
    int Right = n - 1;
    int i;
    while(Left<Right)
    {
        for(i = Left; i<Right; i++)
            if( a[i].finish>a[i+1].finish)
                Swap(&a[i], &a[i+1]);
            Right--;
        for(i = Right; i>Left; i--)
            if( a[i].finish<a[i-1].finish)
                Swap(&a[i], &a[i-1]);
            Left++;
    }
}
int main()
{
    printf("--------------------------\n");
    printf("        BAI TOAN XEP LICH       \n");
    printf("Writen by Nguyen Van Luan\n");
    printf("------------------------------\n");
    FILE *input, *output;
    if((input=fopen("Xep_lich_input.txt","r"))==NULL)
    {
        printf("Loi!khong mo duoc file");
        exit(1);
    }
    int n=0;
    lophoc C[1000],O[1000];
    int i=0,num=0;
    printf("\nDu lieu vao:\n");
    while(fscanf(input,"%d",&num)!=EOF)
    {
        if(i%3==2)
           {
               C[n].finish=num;
               printf("%d) ",num);
           }
        else
           if(i%3==1)
           {
                C[n].start=num;
                printf("%d-",num);
           }
           else
                {
                    C[n].id=num;
                    printf(" %d(",num);
                }
        i++;
        if(i%3==0) n++;
    }
    fclose(input);
    printf("\nTong so lop hoc:%ld\n",n);
    ShakerSort(C,n);
    printf("Cac lop sap theo thu tu tang dan cua thoi gian ket thuc:\n");
    for(i=0;i<n;i++)
    {
        printf("%d(%d-%d) ",C[i].id,C[i].start,C[i].finish);
    }
    O[0]=C[0];
    int k=C[0].finish;
    int count=1;
    for(i=1;i<n;i++)
    {
        if(C[i].start>k)
        {
            O[count]=C[i];
            k=O[count].finish;
            count++;
        }
    }
    output=fopen("Xep_lich_output.txt","w");
    printf("\nWriting...");
    fprintf(output,"\nSo lop toi uu:%d\n",count);
    printf("\nSo lop toi uu:%d\n",count);
    for(i=0;i<count;i++)
    {
        fprintf(output,"%8d%8d%8d\n",O[i].id,O[i].start,O[i].finish);
        printf("%8d(%d-%d)",O[i].id,O[i].start,O[i].finish);
    }
    fclose(output);
    printf("\nDone!\n");
}