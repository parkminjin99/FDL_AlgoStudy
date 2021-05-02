#include<iostream>
#include<queue>
using namespace std;

#define MAX_N 1001
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
bool map[MAX_N][MAX_N], visited[MAX_N];
int N;

void DFS(int V)
{
    cout << V << ' ';
    visited[V] = 1;
    for (int i = 1; i <= N; i++)
    {
        if(visited[i] == 1 || map[V][i] == 0)
            continue;
        DFS(i); // 재귀 이용
    }
}

void BFS(int V)
{
    queue<int> q;
    q.push(V);
    visited[V] = 0;
    int v;
    while(!q.empty())
    {
        v = q.front();
        cout << q.front() << ' ';
        q.pop();
        for (int i = 1; i <= N; i++)
        {
            if(visited[i] == 0 || map[v][i] == 0)
                continue;
            q.push(i);
            visited[i] = 0;
        }
        
    }
}


int main()
{
    FIO;
    int M, V, x, y;
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }
    DFS(V);
    cout << '\n';
    BFS(V);
    return 0;
}
