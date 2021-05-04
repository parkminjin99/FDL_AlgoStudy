#include <iostream>
#include <vector>
using namespace std;





int main()
{
    int T;  // Test case의 개수
    cin >> T;

    for(int numTestCases = 0; numTestCases < T; numTestCases++) {
        int N;  // 순열의 크기
        cin >> N;
        
        int check[1001] = {0, };
        int per[1001] = {0, };  // 순열

        for(int i = 1; i < N + 1; i++) {
            int tmp;
            cin >> tmp;
            per[i] = tmp;   
        }

        int num_cycle = 0;  // 사이클의 개수

        for(int i = 1; i < N + 1; i++) {
            int first = i;
            if(check[first] == 1)
                continue;

            check[first] = 1;
            while(1) {
                check[per[first]] = 1;
                first = per[first];
            
                if(first == i) {
                    num_cycle += 1;
                    break;
                }
            }
        }

        cout << num_cycle << endl;

    }


    return 0;
}