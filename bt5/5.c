#include<stdio.h>
#include<conio.h>
#include<math.h>

float ps(float n)
{
    if(n==1)
        return (float)1/(n*(n+1));
    else
        return ps(n-1) + (float)1/(n*(n+1));
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong la: %.2f", ps(n));
    return 0;
}