#include<iostream>
using namespace std;
#define MAX_N 1001
bool map[MAX_N][MAX_N], visited[MAX_N];
int N;

void DFS(int start)
{
    visited[start] = 1;
    for (int i = 1; i <= N; i++)
    {
        if(visited[i] == 0 && map[start][i] == 1)
            DFS(i);
    }
    
}

int main()
{
    int M, x, y, Ans = 0;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> x >> y;
        map[x][y] = map[y][x] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        if(visited[i] == 0)
        {
            DFS(i);
            Ans++;
        }
    }
    cout << Ans << '\n';
    return 0;
}
