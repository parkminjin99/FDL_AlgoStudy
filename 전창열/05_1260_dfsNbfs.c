#include <stdio.h>
#include <stdlib.h>

int edge[1001][1001];
int visited[1001];
int u, v;
int N, M, V;

//bfs ��  queue�� �̿��ϹǷ� queue�� ���� �ڵ�� scpc�ڵ带 �����Ͽ����ϴ�.
struct node {
    int value;
    struct node* next;
};

struct queue {
    struct node* front;
    struct node* rear;
    int size;
};

void queue_init(struct queue* q) {
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;
}
void queue_push(struct queue* q, int val) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = NULL;
    newNode->value = val;
    q->size++;
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
void queue_pop(struct queue* q) {
    if (q->front->next == NULL) {
        q->front = q->rear = NULL;
        q->size--;
    }
    else if (q->front->next != NULL) {
        struct node* removeNode = q->front;
        q->front = q->front->next;
        q->size--;
        free(removeNode);
    }
}
int queue_front(struct queue* q) {
    return q->front->value;
}

// ������� queue����

void bfs(int cur) {
    struct queue q;
    queue_init(&q);     // queue ����
    visited[cur] = 1;   // ��ó�� ��ġ 1�� ����.
    queue_push(&q, cur);// queue�� ó���� ����. 
    while (q.size) {    // q�� �� ������������
        int here = queue_front(&q); //queue�� �� �հ� ���
        printf("%d ", here);
        queue_pop(&q);  //�Ǿ� ����
        for (int there = 1; there <= N; there++) {
            if (visited[there] || (edge[here][there] == 0)) 
                continue;   //�̹� ���õǾ��� (visited), ����Ǿ����� �ʴ�. (edge=0)
            visited[there] = 1; // �̹��� �����ϴ� �κп� 1
            queue_push(&q, there);  // q�� �ش� �κ� �߰�.
        }
    }
}

int dfs(int cur) {
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0) 
            continue; // �̹� ���õǾ��� (visited), ����Ǿ����� �ʴ�. (edge=0)
        dfs(i);
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1; // u -> v ����
        edge[v][u] = 1; // v -> u ����
    }
    dfs(V);
    printf("\n");
    for (int i = 0; i < 1001; i++)
        visited[i] = 0;     // visited �ʱ�ȭ
    bfs(V);
}
