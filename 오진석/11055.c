#include <stdio.h>

int main()
{
    int A[1001], DP[1001], N, max = 0; //A : 수열 배열, DP : 현재 위치까지의 증가 부분 수열 배열
                                       // N : A의 크기, max : 최댓값
    int i,j;
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++)
    {
        scanf("%d", &A[i]);
    }
    
    for(i = 0; i<N; i++)
    {
        DP[i] = A[i];
        
        for(j = 0; j < i; j++)
        {
            if((A[j] < A[i]) && (DP[i] < A[i] + DP[j]))
            {
                DP[i] = DP[j] + A[i];
            }
        }
        if(max < DP[i])
        {
            max = DP[i];
        }
        
    }
    printf("%d", max);
}
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
