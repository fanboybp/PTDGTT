#include<stdio.h>
#include<math.h>

int tongchan(int n)
{
    if(n<10)
    {
       if(n%2==0)
            return n;
       else
            return 0; 
    }
    else
    {
        if((n%10) % 2==0)
            return tongchan(n/10) +(n%10);
        else
            return tongchan(n/10);
    }
}

int main()
{
    int n;
    printf("Nhap n: "); scanf("%d", &n);
    printf("So cac chu so la: %d", tongchan(n));
    return 0;
}