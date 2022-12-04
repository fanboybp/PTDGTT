#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct 
{
    int id;
    int start;
    int finish;
} lophoc ;
void Swap(lophoc *x, lophoc *y)
{
    lophoc temp = *x;
            *x = *y;
            *y = temp;
}
void seletionSort(lophoc mang[], long n)
{
    long i,j, iMin;
    for( i=0; i<n -1; i++)
    {
        iMin = i;
        for(j = i+1; j<n;j++)
            if(mang[j].finish<mang[iMin].finish)
            iMin = j;
    }
    if(i!= iMin)
        Swap(&mang[i], &mang[iMin]);
}

int main()
{
    printf("----------------\n");
    printf("    BAI TOAN XEP LICH \n");
    printf("Writen by Nguyen Van Luan\n");
    printf("--------------------\n");

    FILE *fin, *fout;
    if((fin=fopen("file xep_lich_input.txt", "r"))==NULL)
    {
        printf("Loi mo file!");
        exit(1);
    }
    int n=0;
    lophoc C[1000], O[1000];
    int i=0, num=0;
    while(fscanf(fin, "%d", &num) !=EOF)
    {
        if( i % 3 == 2)
            {
                C[n].finish = num;
                printf("%d) ", num);
            }
            else
                if(i%3==1)
                    {
                        C[n].start = num;
                        printf("%d-", num);
                    }
                    else
                    {
                        C[n].id = num;
                        printf(" %d(",num);
                    }
                    i++;
                if(i%3==0)      n++;
    }
    fclose(fin);
    printf("\nTong so lop hoc : %ld\n", n);
    seletionSort (C,n);
    printf("Cac lop sap theo thu tu tang dan cua thoi gian ket thuc:\n");
    for(i = 0;i<n;i++)
    {
        printf("%d(%d-%d) ", C[i].id, C[i].start, C[i].finish);
    }
    O[0] = C[0];
    int k = C[0].finish;
    int count = 1;
    for(i =1 ; i< n;i++)
    {
        if(C[i].start>k)
        {
            O[count] = C[i];
            k = O[count].finish;
            count++;
        }
    }
    fout=fopen("file xep_lich_output.txt", "w");
    printf("\nWriting...");
    fprintf(fout, "\nSo lop toi uu:%d\n", count);
    for(i = 0; i<count; i++)
    {
        fprintf(fout, "%8d%8d%8d\n", O[i].id, O[i].start, O[i].finish);
        printf("%8d(%d-%d)", O[i].id, O[i].start, O[i].finish);
    }
    fclose(fout);
    printf("\nDone!\n");
}
