#include <stdio.h>

int main()
{
    int n,m;
    printf("Nhap vao gia tri n, m: ");
    scanf("%d %d",&n,&m);
    printf("Hinh ung voi n, m la:\n");
    for (int i = 0; i < n; i++)
    {
        printf("*");
        for (int j = 0; j < m-1; j++)
        {
            if(i==0 || i==n-1)
                printf("\t*");
            else
            {
                printf("\t");
                if (j==m-2 )
                {
                    printf("*");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
