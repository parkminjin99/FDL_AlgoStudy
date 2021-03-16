#include<stdio.h>

int main()
{
    int N, K, i, a[11];
    int j = 0;
    scanf("%d %d", &N, &K);
    
    for (i = 1; i <= N; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for (i = N; i > 0; i--)
    {
        j += K / a[i];
        K %= a[i];
    }
    
    printf("%d\n", j);
    return 0;
}
