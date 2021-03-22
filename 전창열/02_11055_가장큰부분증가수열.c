#include <stdio.h>

int main()
{
	int N, A[1001]={0,},answer=0; // N:수열 전체수, A: 수얼의 수, answer: 답으로 출력
    
	scanf("%d", &N);	
    for(int i=0;i<N;i++)
    {
        scanf("%d", &A[i]);	
    }

    /*
        A        =   [a_0, a_1, ....., a_n]
        1. sum[0]에는 a_0 저장
        2. sum[1]에는 a_0<a_1 인 경우 a_0 + a_1 저장 / 아닌 경우 a_1 저장 
        3. sum[2]에는 a_0<a_2 인 경우 temp에 a_0 + a_1 저장 / a_1<a_2 인 경우 temp에 a_1 + a_2 저장 / 아닌 경우 a_2 저장
           만약 a_0<a_2 , a_1<a_2를 모두 만족시 둘중 더 큰수를 저장. 

        즉 sum[k]에는 a_0~ a_k에 대해 a_k를 포함하면서 만들수있는 가장 큰 수의 합이 저장됨.
        따라서 sum[k+1]을 만들때는 a_i<a_k를 만족하는 (0=<i<k) 것중에서 가장 큰합을 저장하는 경우와 비교하면됨. 

        해당 과저을 거치고 sum중 가장 큰 값을 저장하고 있는 값을 출력하면답. 
    */

    int sum[1001]={0,};  // sum 저장
    int temp=0;          // 값비교를 위한 변수

    sum[0]=A[0];         // 초기 1개 설정

    for(int i=1;i<N;i++)
    {
        temp=0;          // i가 바뀔때마다 최대 설정을 다시하므로
        for(int j=0;j<i;j++)        //i보다 작은 인덱스에 대함
        {
            if((A[j]<A[i])&&(temp<sum[j]))  //a_j<a_i를 만족하면서 sum_j가 가장 큰경우 찾기
            {
                temp=sum[j];            
            }
        }
        sum[i]=temp+A[i];                   // 찾은 값을 a_i와 더해 sum[i]로 설정
    }

    for(int i=0;i<N;i++)                    //가장 큰 sum 찾기
    {
        if(answer<sum[i])
            answer=sum[i];
    }

    printf("%d",answer);

	return 0;

}
