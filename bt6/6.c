#include<stdio.h>
#include<conio.h>
#include<math.h>

float ps(float n)
{
    if(n==0)
        return (float)1/2;
    else
        return ps(n-1) + (float)(2*n + 1)/(2*n + 2);
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong la: %.2f", ps(n));
    return 0;
}