#include<stdio.h>
#include<conio.h>
#include<math.h>

long Tong(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return Tong(n-1) + n;
}

int main()
{
    printf("----------------------\n");
    printf("        BAI TAP DE QUY      \n");
    printf("-------------------------\n");

    int n;
    printf("Nhap n: \n"); scanf("%d", &n);
    printf("ket qua : %d\n", Tong(n));
    return 0;
}