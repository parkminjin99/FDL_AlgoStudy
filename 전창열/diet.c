#include <stdio.h>
#include <stdlib.h>

int compare(void* first, void* second)  // �������� qsort�� ���� ���Լ� �ۼ�
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

	scanf("%d", &T);    //T(test case ����) �Է�
	
	for (test_case = 0; test_case < T; test_case++)
	{
		int N, K;   //N: �޴���, K: ��¥��
		int temp;
		int Answer=0;

		int A[200001], B[200001];   // �� �޴��� Į�θ�����(A,B�Ĵ�)
		
		scanf("%d %d", &N, &K);         //N,K �Է�
		for (int i = 0; i < N; i++ )
			scanf("%d", &A[i]);
		
		qsort(A, N, sizeof(int), compare);  //A������������

		for (int i = 0; i < N; i++)
			scanf("%d", &B[i]);
		
		qsort(B, N, sizeof(int), compare); //B������������

		for (int i = 0; i < K; i++)
		{
			temp = A[i] + B[K - 1 - i];   //A������, B������ ������ ��Ī
			Answer = Answer < temp ? temp : Answer;     // ���� �� ū��� answer�� ����
		}

		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer);

	}
	return 0;
}