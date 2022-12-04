#include<stdio.h>
#include<math.h>
#include<conio.h>

long Tong (int n)
{
    if(n<10)
        return n;
    else 
        return Tong(n/10) +(n%10);
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Tong cac chu so cua so nguyen duong la: %d", Tong(n));
    return 0;
}