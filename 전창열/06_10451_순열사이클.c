#include <stdio.h>

int edge[1001][1001];
int tmp[1001]={0,};
int visited[1001];
int u, v;
int N;

int dfs(int cur) {  //이전에 사용한 dfs 알고리즘 이용.
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0)
            continue; // 이미사용 (visited!=0), 연결되어있지 않음 (edge=0)
        dfs(i);
    }
}

//이전에 사용한 dfs 사용
int main() {
    int count=0;
    int T;
    scanf("%d", &T);        //반복횟수
    for(int j=0;j<T;j++){
        scanf("%d", &N);    //수열 원소개수
        for (int i = 1; i <= N; i++) {
            scanf("%d", &v);    
            edge[i][v] = 1; // u -> v 연결. 이번문제의 경우 일방향
            tmp[i]=v;       //edge를 여러번사용해야하는데, [1001][1001]을 계속 전부 초기화 하면 
                            //시간초과가 되므로 사용하는 부분만 저장하고 추후 해당부분 초기화 
        }
        for (int i = 1; i <= N; i++) {
            if (visited[i]==0) { // visited 되지 않은 항목에 대해 그래프 생성
                dfs(i);
                count++;    //그래프 한번 생성시 count 1증가
            }
        }
        printf("%d\n", count);  // 한줄씩 출력이므로 \n 해야함. 
        count=0;                // 썻던 변수 초기화
        for(int k=1;k<=N;k++)
        {
            visited[k]=0;       
            edge[k][tmp[k]]=0;
            tmp[k]=0;
        }   
    }
    return 0;
}

