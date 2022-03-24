#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define M_a 10000

void Nhap(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
    }
}

void In(int a[], int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}


int Tontai(int a[], int n, int value)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]==value)
            return true;
    }
    return false;
}

int Demso(int a[], int n, int value)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==value)
        {
            s = s + 1;
        }
    }
    return s;
}

int main()
{
    int a[M_a];
    int n, value ;
    scanf("%d", &n);
    Nhap(a, n);
    scanf("%d", &value);
    if(Tontai(a, n, value)== true)
    {
        int s=Demso(a, n, value);
        printf("The value %d appears %d time(s)\n", value, s);
        printf("At the following position(s): ");
        for(int i=1;i<=n;i++)
        {
            int S=0;
            S = S + 1;
            while(Tontai(a, n, value)== true)
            {
                printf("%d ", S);
            }

        }
    }
    else
    {
        printf("The value %d does not exist in the given array", value);
    }


}