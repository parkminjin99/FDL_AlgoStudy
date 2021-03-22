#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A, B, K, N, T, result;
    cin >> T;
    for(int i = 0; i < T; i++){
        vector<int> A_vec;              // A, B 식당의 가격을 넣을 곳
        vector<int> B_vec;
        vector<int> R;
        cin >> N >> K;
        for(int j = 0; j < N; j++){
            cin >> A;
            A_vec.push_back(A);
        }
        for(int j = 0; j < N; j++){
            cin >> B;
            B_vec.push_back(B);
        }
        sort(A_vec.begin(), A_vec.end());  // A, B를 정렬
        sort(B_vec.begin(), B_vec.end());

        for(int j = 0; j < K; j++){
            result = A_vec[j] + B_vec[K - j - 1];   // 최대 칼로리를 최소화하기
            R.push_back(result);
        }
        sort(R.begin(), R.end());  // 정렬 -> 최대 칼로리는 R[K-1]에 저장

        cout << "Case #" << i+1 << endl;
        cout << R[K-1] << endl;
    }

    return 0;
}