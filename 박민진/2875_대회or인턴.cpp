#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int N,M,K, ans,r;
    cin >> N >> M >> K;
    ans = min(N/2,M); // �ִ�� ������ �� �ִ� ���� ���� 
    int i;
    for (i = ans; i >= 0; i--) // ���� ������ ���̸鼭 K���� ������ Ȯ��
        if(K <= ((N-i*2)+(M-i))) 
            break;
    cout << i << '\n';
    return 0;
}