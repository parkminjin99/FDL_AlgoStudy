#include <stdio.h>

int edge[1001][1001];
int tmp[1001]={0,};
int visited[1001];
int u, v;
int N;

int dfs(int cur) {  //������ ����� dfs �˰��� �̿�.
    visited[cur] = 1;
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0)
            continue; // �̹̻�� (visited!=0), ����Ǿ����� ���� (edge=0)
        dfs(i);
    }
}

//������ ����� dfs ���
int main() {
    int count=0;
    int T;
    scanf("%d", &T);        //�ݺ�Ƚ��
    for(int j=0;j<T;j++){
        scanf("%d", &N);    //���� ���Ұ���
        for (int i = 1; i <= N; i++) {
            scanf("%d", &v);    
            edge[i][v] = 1; // u -> v ����. �̹������� ��� �Ϲ���
            tmp[i]=v;       //edge�� ����������ؾ��ϴµ�, [1001][1001]�� ��� ���� �ʱ�ȭ �ϸ� 
                            //�ð��ʰ��� �ǹǷ� ����ϴ� �κи� �����ϰ� ���� �ش�κ� �ʱ�ȭ 
        }
        for (int i = 1; i <= N; i++) {
            if (visited[i]==0) { // visited ���� ���� �׸� ���� �׷��� ����
                dfs(i);
                count++;    //�׷��� �ѹ� ������ count 1����
            }
        }
        printf("%d\n", count);  // ���پ� ����̹Ƿ� \n �ؾ���. 
        count=0;                // ���� ���� �ʱ�ȭ
        for(int k=1;k<=N;k++)
        {
            visited[k]=0;       
            edge[k][tmp[k]]=0;
            tmp[k]=0;
        }   
    }
    return 0;
}

