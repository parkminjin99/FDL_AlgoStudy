#include <stdio.h>

int main()
{
	int N, K, count, R;	//주어진 값
	int N_won[11] = { 0, };	//동전은 최대 10개
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &N_won[i]);
	count = 0;

	for (int i = N - 1; i >= 0; i--) // 동전은 오름차순 입력이므로 큰수부터 몇개씩 쓸수있는지 계산
	{
		count += K / N_won[i];		// 해당 단위로 사용가능 개수
		R = K % N_won[i];		// 남는것은 다음 단위로 하기위해 준비
		K = R;
	}
	printf("%d", count);
	return 0;
}
