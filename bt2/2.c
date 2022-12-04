#include<stdio.h>
#include<conio.h>
#include<math.h>

int TongBP(int n)
{
    if(n==1)
        return 1;
    else   
        return TongBP(n-1) + n*n;
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong binh phuong la: %d\n", TongBP(n));
    return 0;
}