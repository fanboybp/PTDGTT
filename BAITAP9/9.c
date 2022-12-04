#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
char lcs_string[100];  
int lcs_max;
int Max(int x, int y)
{
    if(x>y)  
        return x;
    else
        return y;
}
void LCS_build(char X[], char Y[])
{
    int m=strlen(X); 
    int n=strlen(Y); 
    printf("m,n = %d\n",m,n);
    int C[100][100],i,j;  
    for(int i=0;i<=m;i++)   C[i][0]=0;   
    for(int j=0; j<=n; j++)     C[0][j]=0;
    printf("Y:%s\n", Y);
    printf("X:%s\n", X);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(X[i-1]==Y[j-1])
                C[i][j]=1+C[i-1][j-1];
            else
                C[i][j]=Max(C[i][j-1], C[i-1][j]);
        lcs_max=C[m][n];  
        int index = lcs_max; 
        lcs_string[index + 1] = '\0';  
        i = m; j = n;
        while(i>=0 && j>=0)
        {
            if(X[i-1]==Y[j-1])
            {
                index--;
                lcs_string[index] = X[i -1];
                i--;
                j--;
            }
            else if(C[i -1][j] > C[i][j-1])
                {
                    i--;
                }
            else
                j--;
        }
    printf("\nLCS:%s\n", lcs_string);
}
int main()
{
    printf("-----------------------\n");
    printf("        QUY HOACH DONG      \n");
    printf("    CHUOI CON CHUNG DAI NHAT    \n");
    printf("Writen by Nguyen Van Luan\n");
    printf("---------------------------------------\n");
    char X[100], Y[100];  
    FILE *fin, *fout;
    if((fin=fopen("input_string.txt","r")) == NULL)
    {
        printf("Loi! Khong mo duoc file");
        exit(1);
    }
    fgets(Y,100,fin);  
    Y[strlen(Y)-1]='\0';  
    fgets(X,100,fin);
    X[strlen(X)-1]='\0';
    printf("Y:%s\n", Y);
    printf("X:%s\n", X);
    fclose(fin);
    LCS_build(X,Y); 
    fout=fopen("output_string.txt","w");
    printf("Ket qua: \n");
    printf("max: %d\n", lcs_max);
    printf("LCS: %s\n",lcs_string);
    fprintf(fout,"LCS:\n");
    fprintf(fout,"%s\n", X);
    fprintf(fout,"%s\n", Y);
    fprintf(fout,"%d", lcs_max);  
    fprintf(fout,"\n");
    fputs(lcs_string,fout);   
    fclose(fout);
    printf("\nDone!\n");
}