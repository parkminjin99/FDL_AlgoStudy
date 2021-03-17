#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 200001

int Answer;
bool comp(int a, int b)
{
    return a > b;
}

int main(int argc, char** argv)
{
    int T, test_case, N, K, A[MAX_N], B[MAX_N];
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        Answer = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> A[i];
        for (int i = 0; i < N; i++)
            cin >> B[i];
        sort(A,A+N); // 오름차순 정렬
        sort(B,B+N,comp); // 내림차순 정렬
        // 오름차순, 내림차순 정렬을 해서 최대 칼로리를 섭취한 날의 칼로리 양을 최소화
        for (int i = 0; i < K; i++) 
            Answer = max(Answer, A[i] + B[i+N-K]); // 최대 칼로리를 섭취한 날을 구하기
        
        cout << "Case #" << test_case+1 << endl;
        cout << Answer << endl;
    }

    return 0;
}
