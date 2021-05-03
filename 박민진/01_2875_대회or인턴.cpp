#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,M,K, ans,r;
    cin >> N >> M >> K;
    ans = min(N/2,M); // 최대로 생성될 수 있는 팀의 개수 
    int i;
    for (i = ans; i >= 0; i--) // 팀의 개수를 줄이면서 K명이 남는지 확인
        if(K <= ((N-i*2)+(M-i))) 
            break;
    cout << i << '\n';
    return 0;
}
