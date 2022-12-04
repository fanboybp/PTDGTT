#include<stdio.h>
#include<math.h>
#include<conio.h>

float ps2( float n )
{
    if(n==1)
        return (float)1/2;
    else
        return ps2(n-1) + (float)1/(2*n);
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong cac so la: %.2f", ps2(n));
    return 0;
}