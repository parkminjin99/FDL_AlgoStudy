#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, M, K;        // 순서대로 여학생의 수, 남학생의 수, 인턴쉽에 참여해야 하는 인원 수
    cin >> N >> M >> K; 

    int max_team = 0;   // 최대의 팀 수를 저장할 변수
    
    for(int i = 0; i < K; i++)
    {
        if (N > 2 * M) {    // 여학생이 남학생의 두배보다 같거나 많은 경우 여학생 한명을 인턴쉽으로 보낸다.
            N -= 1;
        }
        else {
            M -= 1; // 반대의 경우 남학생 한명을 인턴쉽으로 보낸다.
        }

    }


    if (N <= 0 || M <= 0) {  // 남학생과 여학생 중 0명이 있는 경우
        max_team = 0;

    }
    else {
        if (N >= 2 * M)         // 여학생 >= 남학생
            max_team = M;
        else 
            max_team = N / 2;
    }

    cout << max_team;

    return 0;
}