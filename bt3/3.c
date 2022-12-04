#include<stdio.h>
#include<conio.h>
#include<math.h>

float ps(float n)
{
    if(n==0 || n==1)
        return 1;
    else
        return ps(n-1) + 1/n;
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("tong cac so la : %.2f\n", ps(n));
    return 0;
}