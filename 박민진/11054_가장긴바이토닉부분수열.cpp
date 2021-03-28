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
    
    int DP[MAX_N] = {0,};           // 가장 긴 증가하는 부분 수열 저장 배열
    int reverse_DP[MAX_N] = {0,};   // 배열을 거꾸로 했을 때 가장 긴 증가하는 수열 저장 배열
    for (int i = 1; i <= N; i++)
    {
        DP[i] = reverse_DP[N-i+1] = 1;
        for (int j = 1; j < i; j++)
        {
            if(arr[j] < arr[i])         // DP[i]에 i번째 수까지의 가장 큰 증가 부분 수열의 합 입력 
                DP[i] = MAX(DP[j]+1, DP[i]);
            if(arr[N-j+1] < arr[N-i+1]) // reverse_DP[N-i+1]에 거꾸로 N-i+1번째 수까지의 가장 큰 증가 부분 수열의 합 입력 
                reverse_DP[N-i+1] = MAX(reverse_DP[N-i+1], reverse_DP[N-j+1]+1);
        }
    }
    int ans = 1;
    for (int i = 1; i <= N; i++)
        ans = MAX(ans,DP[i]+reverse_DP[i]);
    cout << ans-1 << endl;      // 자기 자신의 길이 제거
    return 0;
}