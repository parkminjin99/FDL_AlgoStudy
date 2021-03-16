#include <stdio.h>
#include <stdlib.h>

int compare(void* first, void* second)  // 오름차순 qsort를 위한 비교함수 작성
{
	if (*(int *)first > *(int *)second)
		return 1;
	else if (*(int *)first < *(int *)second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int T, test_case;
	setbuf(stdout, NULL);

	scanf("%d", &T);    //T(test case 종류) 입력
	
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K;   //N: 메뉴수, K: 날짜수
		int temp;
		int Answer=0;

		int A[200001], B[200001];   // 각 메뉴별 칼로리저장(A,B식당)
		
		scanf("%d %d", &N, &K);         //N,K 입력
		for (int i = 0; i < N; i++ )
			scanf("%d", &A[i]);
		
		qsort(A, N, sizeof(int), compare);  //A 오름차순정렬

		for (int i = 0; i < N; i++)
			scanf("%d", &B[i]);
		
		qsort(B, N, sizeof(int), compare); //B 오름차순정렬

		for (int i = 0; i < K; i++)
		{
			temp = A[i] + B[K - 1 - i];   //A낮은값, B높은값 순서로 매칭
			Answer = Answer < temp ? temp : Answer;     // 합이 더 큰경우 answer를 갱신
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}
	return 0;
}
