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

float Tong(float x, int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 1 + x;
    else
        return Tong(x,n-1) + mu(x,n);
}
int main()
{
    int n,x;
    printf("Nhap x: "); scanf("%d", &x);
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong la: %.2f", Tong(x,n));
    return 0;
}