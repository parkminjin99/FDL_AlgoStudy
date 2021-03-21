#include<stdio.h>

int main()
{
    int N, K, i, a[11]; //N : 동전 종류, K : 가치의 합 , a[] 동전의 가치 배열
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
