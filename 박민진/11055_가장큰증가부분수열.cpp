#include <iostream>
using namespace std;
#define MAX_N 1001
#define MAX(x,y)( (x)>(y)?(x):(y) )
int main()
{
    int N, arr[MAX_N] = {0,};
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    int DP[MAX_N] = {0, };  DP[1] = arr[1];
    int ans = DP[1];
    for (int i = 2; i <= N; i++)
    {
       DP[i] = arr[i];
        for (int j = 1; j < i; j++) // DP[i]에 i번째 수까지의 가장 큰 증가 부분 수열의 합 입력 
            if(arr[j] < arr[i])
                DP[i] = MAX(DP[j]+arr[i], DP[i]);
        ans = MAX(ans,DP[i]); 
    }
    cout << ans << endl;
    return 0;
}
