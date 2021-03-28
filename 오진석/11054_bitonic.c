//배열의 i번째까지 LIS를 찾고 역방향으로부터 i까지의 LIS를 찾고나서 두 길이 더하고 최대값을 반환

#include <stdio.h>
int max_fn(int a, int b) // 최댓값 출력 함수
{
    if(a > b)
        return a;
    else if(a < b)
        return b;
    else
        return a;
}

int main()
{
    int N, max = 0; // N : 수열의 원소 개수, max : 최댓값
    scanf("%d", &N);
    
    int dp1[N+1], dp2[N+1], dp[N+1], arr[N+1]; // dp1 : 처음부터 시작하는 LIS, dp2 : 맨뒤부터 시작하는 LIS, dp : dp1, dp2 합쳐 나온 배열
    dp1[0] = 0, dp2[N+1] = 0;
    
    for(int i =1; i<N+1; i++)
    {
        scanf("%d", &arr[i]); //수열 값 입력
    }
        for(int i = 1; i<N+1; i++)
        {
            dp1[i] = 1;
            dp2[N-i+1] = 1;
            for(int j = 1; j < i; j++)
            {
                if ( arr[i] > arr[j] && dp1[j] + 1 > dp1[i])
                {
                    dp1[i] = dp1[j] + 1;
                }
                if ( arr[N-i+1] > arr[N-j+1] && dp2[N-j+1] + 1 > dp2[N-i+1])
                {
                    dp2[N-i+1] = dp2[N-j+1] + 1;
                }
            }
        }
    
    
    for (int i = 1; i < N+1; i++)
    {
           dp[i] = dp1[i] + dp2[i];
           max = max_fn(max, dp[i]);
           
    }
    printf("%d\n", max-1); //dp1[i] + dp2[i] 할때 i 두번 더하므로 1을 빼줌
    
    return 0 ;
}
