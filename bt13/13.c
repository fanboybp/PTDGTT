#include<stdio.h>
#include<math.h>
#include<conio.h>

int USCLN( int a, int b)
{
    if(b == 0)
        return a;
     return USCLN(b, a % b);
}

int main()
{
    int a,b;
    printf("Nhap a = "); scanf("%d", &a);
    printf("Nhap b = "); scanf("%d", &b);
    printf("Uoc so chung lon nhat cua %d va %d la: %d",a,b, USCLN(a,b));
    return 0;
}