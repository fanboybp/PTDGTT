#include<stdio.h>
#include<math.h>
#include<conio.h>

long gt( long n )
{
    if(n>0)
        return n * gt(n-1);
    else
        return 1;
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Giai thua cua n la: %d ", gt(n));
    return 0;
}