#include <stdio.h>

int edge[1001][1001];
int visited[1001];
int u, v;
int N, M;

int dfs(int cur) {  //이전에 사용한 dfs 알고리즘 이용.
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0)
            continue; //이미 선택되었다 (visited), 연결되어있지 않다. (edge=0)
        dfs(i);
    }
}
int main() {
    int count=0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1; // u -> v 연결
        edge[v][u] = 1; // v -> u 연결
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]==0) { // visited 되지 않은 항목에 대해 그래프 생성
            dfs(i);
            count++;    //그래프 한번 생성시 count 1증가
        }
    }
    printf("%d", count);

}
