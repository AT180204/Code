#include <stdio.h>
#include <stdalign.h>

int main()
{
    int a,b,lcm;
    printf("\t\tChuong trinh tim boi chung nho nhat cua hai so!\n");
    printf("\tNhap vao hai so a, b: ");
    scanf("%d%d", &a, &b);

    for (int i = a>b?b:a; i <= a*b; i++)
    {
        if( i%a==0 && i%b==0 )
        {  
            lcm=i;
            break;
        }
    }
    printf("\nBoi chung nho nhat cua hai so %d va %d la: %d\n",a,b,lcm);
    return 0;
}