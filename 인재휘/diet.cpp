#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int A, B, K, N, T, result;
    cin >> T;
    for(int i = 0; i < T; i++){
        vector<int> A_vec;
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
        sort(A_vec.begin(), A_vec.end());
        sort(B_vec.begin(), B_vec.end());

        for(int j = 0; j < K; j++){
            result = A_vec[j] + B_vec[K - j - 1];
            R.push_back(result);
        }
        sort(R.begin(), R.end());

        cout << "Case #" << i+1 << endl;
        cout << R[K-1] << endl;
    }

    return 0;
}