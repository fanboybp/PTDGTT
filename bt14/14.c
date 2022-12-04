#include<stdio.h>
#include<math.h>

int dem(int n)
{
    if(n<10)
        return 1;
    else
        return dem(n/10) +1;
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Dem la: %d", dem(n));
    return 0;
}