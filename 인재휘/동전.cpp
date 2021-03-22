#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;                          // 동전 개수
    int result = 0;                   // 최종 결과 값
    long long price, coin_price;      // price = 목표 값, coin_price = 각 동전의 값
    vector<int> coin;

    cin >> num >> price;
    for(int i = 0; i < num; i++){
        cin >> coin_price; 
        coin.push_back(coin_price);
    }

    num -= 1;
    while(price != 0){                // 목표 값이 0이 될때까지 반복
        if(price >= coin[num]){       // 목표값이 현재 동전의 값보다 크면 목표값 - 동전의 값
            price -= coin[num];      
            result += 1;
        }
        else{                         // 목표값이 현재 동전의 값보다 작으면 동전의 값을 변경
            num -= 1;
        }
    }

    cout << result << endl;
    return 0;
}