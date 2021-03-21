#include <stdio.h>
#include <stdlib.h> //qsort 함수 선언된 헤더 파일

int max(int a, int b) //최댓값 출력 함수
{
    if(a > b)
    {
        return a;
    }
    else if(a < b)
    {
        return b;
    }
    
    else
    {
        return a;
    }
}

int compare(const void *a, const void *b)    // 오름차순정렬 위한 비교 함수
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void)
{
    int T, test_case;
    
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        int answer = 0;
        int A[200000]; //A식당 칼로리 저장
        int B[200000]; //B식당 칼로리 저장
        int N,K; //N : 메뉴 개수, K : 일 수
        
        scanf("%d %d", &N, &K);
        for(int i = 0; i<N; i++)
        {
            scanf("%d", &A[i]);
        }
        
        for(int i = 0; i<N; i++)
        {
            scanf("%d", &B[i]);
        }
        
        qsort(A, N, sizeof(int), compare); // A배열 오름차순 정렬
        qsort(B, N, sizeof(int), compare); // B배열 오름차순 정렬
        
        for(int i =0 ; i<K; i++)
        {
            answer = max(answer, A[i]+B[K-1-i]);
        }
        
        
        printf("Case #%d\n", test_case+1);
        printf("%d\n", answer);
        
    }

    return 0;
}
