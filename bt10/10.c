#include<stdio.h>
#include<math.h>
#include<conio.h>

float mu(float x, int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return x;
    else
        return mu(x,n-1)*x;
}
float tong10(float x, int n)
{
    if(n==1)
        return (x*x);
    else
        return tong10(x,n-1) + mu(x, 2*n);
}

int main()
{
    int n,x;
    //int tong=0;
    printf("Nhap x: "); scanf("%d", &x);
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong la: %.2f", tong10(x,n));
    return 0;
}