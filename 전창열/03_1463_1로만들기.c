#include <stdio.h>

int main()
{
    /**
    입력된 수 N은 3으로 나누거나, 2로나누거나 1을 빼는 과정만을 진행할 수있다. 
    즉 N/3보다 연산을 1번더, 혹은 N/2보다 1번더, 혹은 N-1보다 1번더 연산을 수행하게 된다. 
    또한 주어진 범위는 백만(1,000,000)으로 상대적으로 작은수이므로 모든경우 계산이 가능하다.
    따라서 주어진 범위내로 i를 1부터 증가시켜가면서 
    i/3,i/2,i-1 3가지 수중 가장 적은 횟수에 1은 더하여 i의 연산횟수로 설정한다.  
    **/


	int N,X[1000002]={0,}; // X[i]에는 i를 계산하는데에 필요한 연산량을 저장. 
    int tmp=1000000;       // 최대인 10^6을 1씩 빼서 계산하는 경우도 해당 tmp보다 작은 횟수. (대소관계위한 파라미터)
	scanf("%d", &N);	
    
    X[1]=0;     //초기 1은 연산 0회 
    X[2]=1;     // 2는 연산 1회
    X[3]=1;     // 3은 연산 1회
    for(int i=4;i<=1000000;i++)
    {
        tmp=1000000;    // 작은값을 구하기 위한 파라미터
        if(i%3==0)      //3의배수인경우
        {
            tmp=X[i/3];     //3으로 나눈 값의 횟수 
            //printf("tmp1 : %d   ",tmp);

        }
        if(i%2==0)      //2의 배수인경우
        {
            if(tmp>X[i/2])  //2로 나눈 값의 횟수
                tmp=X[i/2]; 
            //printf("tmp2 : %d   ",tmp);
        }
        if(tmp>X[i-1])      //3의배수와 2의배수 모두 아닌경우
            tmp=X[i-1];     //1뺀 값의 횟수
            //printf("tmp3 : %d   ",tmp);

        X[i]=tmp+1;    //3가지의 경우중 가장 작은 횟수가 tmp에 저장되었으므로 X[i]는 그보다 1회 연산 추가로 진행 
        //printf("X[%d]:%d\n",i,X[i]);
    }

    printf("%d",X[N]);      //입력된 N에 대해 사전계산값 출력

    return 0;
}
