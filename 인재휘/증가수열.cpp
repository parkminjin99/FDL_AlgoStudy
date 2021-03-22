#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int size, num, big_num; //수열 크기, 수열의 수, 제일 큰 수를 저장할 변수
    int arr_sum[1001] = {0, };
    vector<int> Seq, sum; // 수열 저장할 곳
    
    cin >> size;
    for(int i =0; i < size; i++){
        cin >> num;
        Seq.push_back(num);
    }

    arr_sum[0] = Seq[0];
    sum.push_back(Seq[0]);
    for(int i = 1; i < size; i++){               // 현재 위치의 수가 이 전의 위치들의 수보다 크면
        big_num = Seq[i];                        // 해당 위치까지의 합에 더함
        for(int j = 0; j < i; j++){
            if(Seq[i] > Seq[j]){
                arr_sum[i] = sum[j] + Seq[i];
                if(big_num < arr_sum[i]){
                    big_num = arr_sum[i];         // 더한 결과 중 가장 큰 수만 저장
                }
            }
        }
        sum.push_back(big_num);
    }

    sort(sum.begin(), sum.end());

    cout << sum[sum.size()-1] << endl;

    return 0;
}