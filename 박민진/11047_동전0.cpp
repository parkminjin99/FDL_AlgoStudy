#include<iostream>
using namespace std;
#define MAX_N 11
int main()
{
    int N, K, coin[MAX_N], ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> coin[i];
    for (int i = N-1; i >= 0; i--)
    {
        if(coin[i] <= K)
        {
            ans += K/coin[i];
            K -= (K/coin[i])*coin[i];
        }
    }
    cout << ans << endl;
    return 0;
}