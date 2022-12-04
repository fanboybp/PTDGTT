#include<stdio.h>
#include<math.h>

int max2so(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int chusoLN(long n)
{
    if(n<10)
        return n;
    else
        {
            return max2so(chusoLN(n/10), n%10);
        }
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("Chu so lon nhat la : %d", chusoLN(n));
    return 0;
}