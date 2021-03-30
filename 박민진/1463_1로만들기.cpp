#include <iostream>
using namespace std;
#define MAX_N 1000001
#define MIN(x,y)( (x)<(y)?(x):(y) )
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main()
{
    FIO;
    int N;
    cin >> N;
    int DP[MAX_N] = {0,};
    for(int i = 2; i <= N; i++)
    {
        DP[i] = DP[i-1];                                // -1울 했을 떄 
        if(i%2 == 0)    DP[i] = MIN(DP[i],DP[i/2]);     // 2로 나누어 떨어질 때
        if(i%3 == 0)    DP[i] = MIN(DP[i], DP[i/3]);    // 3으로 나누어 떨어질 때
        DP[i]++;
    }
    cout << DP[N] << endl;
    return 0;
}