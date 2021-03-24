#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, temp;      // 수열의 원소 개수, 원소를 임시로 저장할 변수
    cin >> N;

    vector<int> A;  // 수열을 저장할 벡터
    vector<int> memo_a; // 각 위치에서 가장 큰 증가부분수열의 합

    for(int i = 0; i < N; i++) {    // 행렬 A 생성
        cin >> temp;
        A.push_back(temp);
        memo_a.push_back(0);

    }

    for(int i = 0; i < N; i++) {
        memo_a[i] = A[i];  

        for(int j = 0; j < i; j++) {
            int k = 0;  // i 번째 원소 전에 더 작은 원소가 있다면, 그 원소까지의 최댓값에 자신을 더한다.

            if(A[j] < A[i]) // i번째 위치보다 j 번째 위치의 원소가 더 작을경우, j 번째 위치의 최댓값에 자신을 더함.
                k = memo_a[j] + A[i];
            
            if(k > memo_a[i])   // 구한 값이 지금까지 구한 i번째 위치의 최댓값보다 클 경우, 이를 갱신
                memo_a[i] = k;

        }

    }

    sort(memo_a.begin(), memo_a.end()); // 각 위치의 최댓값을 정렬

    cout << memo_a[N-1];

    return 0;
}