#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;      // N: 동전의 종류 수, K: 만들어야 하는 총 합
    cin >> N >> K;

    vector<int> A_i;    // 각 동전의 가치를 저장. A_i[m] < A_i[n] if m < n 
    int a_i;            // 동전의 가치를 저장하는 임시변수

    for(int i = 0; i < N; i++) {
        cin >> a_i;
        A_i.push_back(a_i);

    }

    int num_of_coins = 0;       // 쓰인 동전의 개수
    while(K != 0) {
        if (K >= A_i.back()) {   // K 값이 가장 비싼 동전보다 크다면 그 값을 뺀다. 
            K -= A_i.back();   
            num_of_coins += 1;  // 쓰인 동전의 개수를 1개 증가시킨다.
        }
        else {
            A_i.pop_back();     // 가장 비싼 동전이 K보다 크다면 그 동전을 제거.
        }

    }

    cout << num_of_coins;       // 사용된 동전의 개수 출력


    return 0;
}