#include<stdio.h>
#include<conio.h>
#include<math.h>

long Tich(int n)
{
    if(n<10)
        return n;
    else
        return Tich(n/10) *(n%10);
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tich cac chu so nguyen duong la :%d", Tich(n));
    return 0;
}