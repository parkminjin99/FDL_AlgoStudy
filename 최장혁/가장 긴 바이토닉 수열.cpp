#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() 
{
    int N;  // 수열의 길이
    cin >> N;
    vector<int> A;  // 수열을 저장할 벡터
    vector<int> B;  // 수열을 거꾸로 저장할 벡터
    vector<int> result;     // A, B 벡터의 각 위치 합
    
    vector<int> memo_a;     // 각 위치에서 자신이 끝이 되는 가장 긴 증가수열 크기 저장
    vector<int> memo_b;

    // 행렬 A와 거꾸로 저장하는 행렬 B 생성
    for(int i = 0; i< N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i = 0; i < N; i++) {
        B.push_back(A[N-1-i]);
    }


    for(int i = 0; i < N; i++) {
        memo_a.push_back(1);
        memo_b.push_back(1);

        for(int j = 0; j < i; j++) {
            int k1 = 0;  // i번째 원소 전에 더 작은 원소가 있다면, 그 원소까지의 최대 길에 1을 더한다.

            int k2 = 0;

            if(A[j] < A[i]) // 현재 A위치보다 작은 원소가 존재한다면, 그 원소에 자신을 붙여서 길이를 1 늘린다.
                k1 = memo_a[j] + 1;
            
            if(k1 > memo_a[i])  // 지금 구한 길이가 최대의 길이라면, 최댓값 갱신.
                memo_a[i] = k1;

            if(B[j] < B[i]) // B에 대해서도 동일하게 수행
                k2 = memo_b[j] + 1;
            
            if(k2 > memo_b[i])
                memo_b[i] = k2;
        }

    }

    reverse(memo_b.begin(), memo_b.end());

    for(int i = 0; i < N; i++) {
        result.push_back(memo_a[i] + memo_b[i]);
    }

    sort(result.begin(), result.end());
    
    cout << result[N-1] - 1;

    /*
    for(int i = 0; i < N; i++)
        cout << memo_b[i] << " ";  
    */
   
    return 0;

}