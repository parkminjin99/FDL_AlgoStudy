#include <stdio.h>

int main()
{
	int N, A[1001]={0,},answer=0; // N:수열 전체수, A: 수얼의 수, answer: 답으로 출력
    
	scanf("%d", &N);	
    for(int i=0;i<N;i++)        // 수 입력
    {
        scanf("%d", &A[i]);	
    }

    /*
        A    =   [a_0, a_1, ....., a_n]
        바이토닉 수열은 양쪽으로 구분됨. 따라서 한쪽씩 개수를 세서 합치는 과정으로 진행. 

        count_up[i]는 i보다 작은 인덱스에 대해 a_i보다 작은 수로 만들수있는 최대 길이의 증가수열
        count_down[i]는 i보다 큰 인덱스에 대해 a_i보다 작은 수로 만들수있는 최대 길이의 감소수열

        1. count_up[0]에는 0 저장
        2. count_up[1]에는 a_0<a_1 인 경우 count_up[0]+1 저장 / 아닌 경우 0 저장 
        3. count_up[2]에는 a_0<a_2 인 경우 temp에 count_up[0]+1 저장 / a_1<a_2 인 경우 temp에 count_up[1]+1 저장 
           / 아닌 경우 a_2 저장
           만약 a_0<a_2 , a_1<a_2를 모두 만족시 둘중 더 큰수를 저장. 

        즉 count_up[k]에는 a_0~ a_k에 대해 a_k보다 작은수로 만들수있는 가장 긴 증가수열의 길이가 저장됨. (a_k가 빠지므로 수열개수 -1형태)
        따라서 count_up[k+1]을 만들때는 a_i<a_k를 만족하는 (0=<i<k) 것중에서 가장 긴 길이를 저장하는 경우와 비교하면됨. 

        1. count_down[N-1]에는 0 저장
        2. count_down[N-2]에는 a_{N-2}}>a_{N-1} 인 경우 count_down[N-1]+1 저장 / 아닌 경우 0 저장 
        3. count_down[N-3]에는 a_{N-3}}>a_{N-1} 인 경우 temp에 count_down[N-1]+1 저장 / a_{N-3}}>a_{N-2} 인 경우 
           temp에 count_down[N-2]+1 저장 / 아닌 경우 a_2 저장
           만약 a_{N-3}}>a_{N-1}, a_{N-3}}>a_{N-2}를 모두 만족시 둘중 더 큰수를 저장. 

        즉 count_down[k]에는 a_k~ a_{N-1}에 대해 a_k를 포함하면서 만들수있는 가장 긴 감소수열의 길이가 저장됨. (a_k가 빠지므로 수열개수 -1형태)
        따라서 count_down[k-1]을 만들때는 a_k<a_i를 만족하는 (k<i<N) 것중에서 가장 긴 길이를 저장하는 경우와 비교하면됨. 


        위의 과정을 거친후 count_down[i]+count_up[i]의 합이 가장 긴경우를 출력한다. 
        이때 a_k가 증가, 감소때 모두 포함되지 않으므로 +1을해서 a_k의 경우까지 추가한다.        
    */

    int count_up[1001]={0,};      // 증가수열
    int count_down[1001]={0,};      //감소수열
    int temp=0;                     //반복문내 비교변수

    for(int i=1;i<N;i++)
    {
        temp=0;          // i가 바뀔때마다 최대 설정을 다시하므로
        for(int j=0;j<i;j++)        //i보다 작은 인덱스에 대함
        {
            if((A[j]<A[i])&&(temp<count_up[j]+1))  //a_j<a_i를 만족하면서 수열의 원소 개수가 가장 큰경우 찾기
            {
                temp=count_up[j]+1;            //+1
            }
        }
        count_up[i]=temp;                   //설정 길이를 count_up[i]
    }


    for(int i=N-2;i>=0;i--)
    {
        temp=0;          // i가 바뀔때마다 최대 설정을 다시하므로
        for(int j=N-1;j>i;j--)        //    i보다 큰 인덱스에 대함
        {
            if((A[i]>A[j])&&(temp<count_down[j]+1))  //a_j<a_i를 만족하면서 수열의 원소 개수가 가장 큰경우 찾기
            {
                temp=count_down[j]+1;            //+1
            }
        }
        count_down[i]=temp;                   //설정 길이를 count_down[i]

    }
    
    for(int i=0;i<N;i++)                    //가장 큰 sum 찾기
    {
        if(answer<count_up[i]+count_down[i])    // 해당 수를 기준으로 증가수열+감소수열 개수
            answer=count_up[i]+count_down[i];
    }

    printf("%d",answer+1);      // 해당수를 빼고 계산하므로 +1

	return 0;

}