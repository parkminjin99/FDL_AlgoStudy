#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int size, num, big_num; //수열 크기, 수열의 수, 제일 큰 수를 저장할 변수
    int up_sum[1001] = {0, };
    int down_sum[1001] = {0, };
    vector<int> Seq, reverse_Seq, answer; // 수열 저장할 곳
    
    cin >> size;
    for(int i =0; i < size; i++){
        cin >> num;
        Seq.push_back(num);
        reverse_Seq.push_back(num);
    }

    reverse(reverse_Seq.begin(), reverse_Seq.end());
    
    up_sum[0] = 1;
    for(int i = 1; i < size; i++){                         // 본인을 기준으로 점점 커지는 수열의 길이 구하기
        big_num = 0;
        for(int j = 0; j < i; j++){
            if(Seq[j] < Seq[i] && big_num < up_sum[j]){
                big_num = up_sum[j];
            }
        }
        up_sum[i] = big_num + 1;
    }

    down_sum[0] = 1;
    for(int i = 1; i < size; i++){                         // 본인을 기준으로 점점 작아지는 수열의 길이 구하기
        big_num = 0;
        for(int j = 0; j < i; j++){
            if(reverse_Seq[j] < reverse_Seq[i] && big_num < down_sum[j]){
                big_num = down_sum[j];
            }
        }
        down_sum[i] = big_num + 1;
    }

    for(int k = 0; k < size; k++){
        answer.push_back(up_sum[k] + down_sum[size-k-1]); // 모든 바이토닉 수열의 길이 구하기
    }
    sort(answer.begin(), answer.end());

    cout << answer[size - 1] - 1 << endl;                 // 중복된 길이 1 빼기

    return 0;
}