#include <stdio.h>
#include <stdlib.h>

int edge[1001][1001];
int visited[1001];
int u, v;
int N, M, V;

//bfs 는  queue를 이용하므로 queue에 대한 코드는 scpc코드를 참고하였습니다.
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

// 여기까지 queue설정

void bfs(int cur) {
    struct queue q;
    queue_init(&q);     // queue 생성
    visited[cur] = 1;   // 맨처음 위치 1로 설정.
    queue_push(&q, cur);// queue에 처음값 설정. 
    while (q.size) {    // q가 다 없어질때까지
        int here = queue_front(&q); //queue의 맨 앞값 출력
        printf("%d ", here);
        queue_pop(&q);  //맨앞 제거
        for (int there = 1; there <= N; there++) {
            if (visited[there] || (edge[here][there] == 0)) 
                continue;   //이미 선택되었다 (visited), 연결되어있지 않다. (edge=0)
            visited[there] = 1; // 이번에 선택하는 부분에 1
            queue_push(&q, there);  // q에 해당 부분 추가.
        }
    }
}

int dfs(int cur) {
    visited[cur] = 1;
    printf("%d ", cur);
    for (int i = 1; i <= N; i++) {
        if (visited[i] != 0 || edge[cur][i] == 0) 
            continue; // 이미 선택되었다 (visited), 연결되어있지 않다. (edge=0)
        dfs(i);
    }
}
int main() {
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);
        edge[u][v] = 1; // u -> v 연결
        edge[v][u] = 1; // v -> u 연결
    }
    dfs(V);
    printf("\n");
    for (int i = 0; i < 1001; i++)
        visited[i] = 0;     // visited 초기화
    bfs(V);
}
