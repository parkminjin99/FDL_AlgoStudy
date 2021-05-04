#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;

int check[1001] = {0,};
int check2[1001] = {0,};
int bridge[1001][1001] = {0,};

int main(){
    int N, M, V;    // 정점의 개수, 간선의 개수, 탐색을 시작할 정점의 번호
    cin >> N;
    cin >> M;
    cin >> V;
    int real_V  = V;


    for(int i = 0; i < M; i++) {
        int temp1, temp2;   // 간선이 연결하는 두 정점의 번호
        cin >> temp1;
        cin >> temp2;

        bridge[temp1][temp2] = 1;
        bridge[temp2][temp1] = 1;
    }


    // Print DFS
    stack<int> s;
    s.push(V);
    check[V] = 1;
    cout << V << " ";
 
    int exit_num = 0;
    while(1) {
        for(int i = 1; i < N + 1; i++) {
            if(bridge[V][i] == 1 && check[i] == 0) {    // 간선을 찾았고, 해당 노드를 방문한 적이 없음
                s.push(i);  // 방문을 기록하기 위해 스택에 추가
                check[i] = 1;
                cout << i << " ";
                V = i;  // 다음에 탐색할 노드
                break;
            }

            if(i == N) {    // 연결된 간선이 없거나, 이미 탐색한 노드밖에 없는 경우
                s.pop();    // 끝에 있는 원소를 삭제     
                
                if(s.empty() == true) { // 모든 노드를 탐색함
                    exit_num = 1;
                }
                else
                    V = s.top();    // 마지막 직전에 탐색한 노드를 다시 이어서 검색한다.

            }         
        }

        if(exit_num == 1)
            break;
    }
    cout << endl;

    if(s.empty() != true)
        printf("stack error\n");

    memset(check, 0, sizeof(check));    // check 배열을 모두 0으로 초기화
    

    V = real_V; // V를 다시 처음 탐색 노드 값으로 초기화
    // Print BFS
    queue<int> q;
    q.push(V);
    check[V] = 1;
    cout << V << " ";

    exit_num = 0;
    while(1) {
        for(int i = 1; i < N + 1; i++) {
            if(bridge[q.front()][i] == 1 && check[i] == 0) {  // 간선이 있고 아직 방문 하지 않은 노드가 존재
                q.push(i);   // 큐에 해당 노드를 추가
                check[i] = 1;
                cout << i << " ";
            }

            if(i == N){  // 큐의 맨 앞 원소는 갈 수 있는 모든 노드를 방문했음
                // printf("\ndelete %d in queue\n", q.front());
                q.pop();    // 큐에서 제거
            }
        }

        if(q.size() == 0) {
            // printf("\n!!\n\n!!\n", q.front());
            break;
        }
    }
    cout << endl;

    if(q.empty() != true)
        printf("queue error\n");



    return 0;
}
