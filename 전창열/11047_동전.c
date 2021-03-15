#include <stdio.h>

int main()
{
	int N, K, count, R;
	int N_won[11] = { 0, };
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &N_won[i]);
	count = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		count += K / N_won[i];
		R = K % N_won[i];
		K = R;
	}
	printf("%d", count);
	return 0;
}
