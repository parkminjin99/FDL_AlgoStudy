#include <stdio.h>

int main()
{
	int N, M, K, tmp;
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	scanf_s("%d", &K);

	tmp = 0;
	if (N > 2 * M)
	{
		tmp = N - 2 * M;
		N = 2 * M;
	}
	else if (N < 2 * M) {
		if (N % 2 == 0) {
			tmp = M - N / 2;
			M = N / 2;
		}else{
			N = N - 1;
			tmp++;
			tmp = M - N / 2;
			M = N/2;
		}
	}
	
	while (tmp < K)
	{
		M--;
		tmp = tmp + 3;
	}
	printf("%d", M);
	return 0;

}
