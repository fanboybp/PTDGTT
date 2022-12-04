#include<stdio.h>
#include<conio.h>
#include<math.h>

int dem(int n)
{
    if(n<10)
    {
       if(n%2!=0)
            return 1;
       else
            return 0; 
    }
    else
    {
        if((n%10) % 2!=0)
            return dem(n/10) +1;
        else
            return dem(n/10);
    }
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("So cac chu so la: %d", dem(n));
    return 0;
}