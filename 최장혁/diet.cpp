#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T; //테스트 케이스의 개수
    cin >> T;

    int num_test_cases;
    for(num_test_cases = 1; num_test_cases < T + 1; num_test_cases++) {
        int N, K;   // 차례대로 식당 메뉴 수, 날짜 수
        cin >> N >> K;

        vector<int> A;  // A 식당의 칼로리 값
        vector<int> B;  // B 식당의 칼로리 값
        vector<int> C;  // 하루 섭취한 칼로리 값

        int food_cal;   // 음식의 칼로리 값을 저장하는 임시 변수
        // A 식당의 메뉴에 들어가는 칼로리 값 저장
        for (int i = 0; i < N; i++) {
            cin >> food_cal;
            A.push_back(food_cal);
        }
        // B 식당의 메뉴에 들어가는 칼로리 값 저장
        for (int i = 0; i < N; i++) {
            cin >> food_cal;
            B.push_back(food_cal);
        }

        // A와 B 식당의 칼로리 값을 오름차순으로 정렬
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int c_cal;  // 그날 먹은 칼로리의 합을 저장하는 임시변수
        for(int i = 0; i < K; i++) {
            c_cal = A[i] + B[K - i - 1];
            C.push_back(c_cal);
        }

        sort(C.begin(), C.end());

        cout << "Case #" << num_test_cases << endl << C.back() << endl;

    }



    return 0;
}