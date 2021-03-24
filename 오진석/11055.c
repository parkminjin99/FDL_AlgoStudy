#include <stdio.h>

// 현재의 값이 이전의 값보다 크면 증가 부분 수열 
// 현재 위치까지의 모든 증가 부분 수열을 배열 DP에 저장

int main()
{
    int A[1001], DP[1001], N, max = 0; // A : 입력할 수열 배열, DP : 현재 위치까지의 증가 부분 수열 배열
                                       // N : A의 크기, max : 최댓값
    int i,j;
    scanf("%d", &N); // N값 입력
    
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &A[i]); // N개만큼 수열 입력
    }
    
    for(i = 0; i<N; i++)
    {
        DP[i] = A[i]; //DP배열에 A배열값 넣기 
        
        for(j = 0; j < i; j++)
        {
            if((A[j] < A[i]) && (DP[i] < A[i] + DP[j]))
            {
                DP[i] = DP[j] + A[i];
            }
        }
        if(max < DP[i])
        {
            max = DP[i]; // 최댓값 갱신
        }
        
    }
    printf("%d", max);
    
    return 0;
}
