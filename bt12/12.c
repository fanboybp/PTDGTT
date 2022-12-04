#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

float mu(float x, int n)
{
    if(n==0)
        return 1;
            if(n==1)
                return x;
        else
            return mu(x,n-1)*x;
}

float tong(float x, int n)
{
    if(n==0)
        {
            printf("Khong tinh duoc!");
            exit(1);
        }
    if(n==1)
        return (x*x)/2;
    else
        return tong(x,n-1) + mu(x,2*n)/(2*n);
}

int main()
{
    int n;
    float x;
    printf("Nhap x: "); scanf("%f", &x);
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong la: %.2f", tong(x,n));
    return 0;
}