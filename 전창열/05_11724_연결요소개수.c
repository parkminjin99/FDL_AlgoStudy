#include <stdio.h>

int edge[1001][1001];
int visited[1001];
int u, v;
int N, M;

int dfs(int cur) {  //������ ����� dfs �˰��� �̿�.
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0)
            continue; //�̹� ���õǾ��� (visited), ����Ǿ����� �ʴ�. (edge=0)
        dfs(i);
    }
}
int main() {
    int count=0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1; // u -> v ����
        edge[v][u] = 1; // v -> u ����
    }
    for (int i = 1; i <= N; i++) {
        if (visited[i]==0) { // visited ���� ���� �׸� ���� �׷��� ����
            dfs(i);
            count++;    //�׷��� �ѹ� ������ count 1����
        }
    }
    printf("%d", count);

}
