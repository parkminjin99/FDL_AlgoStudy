#include <stdio.h>

long long dp[201][201];

int main()
{
    int N, K; // N, K : 입력할 두 정수
    scanf("%d %d", &N, &K);
    
    for(int i = 1; i<=K; i++)
    {
        dp[0][i] = 1; // 1행 2열부터 1행 K열까지 1로 만들기
    }
    
    for(int i = 1; i<=N; i++)
    {
        for(int j = 1; j <=K; j++)
        {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % 1000000000; // 점화식 dp[N][K] = dp[N-1][K] +dp[N][K-1]
        }
    }
    
    printf("%d\n", dp[N][K]);
    return 0;
}
