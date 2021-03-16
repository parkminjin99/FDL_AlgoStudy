#include <iostream>
#include <vector>
using namespace std;

int main(){
    int num;
    int result = 0;
    long long price, coin_price;
    vector<int> coin;

    cin >> num >> price;
    for(int i = 0; i < num; i++){
        cin >> coin_price;
        coin.push_back(coin_price);
    }

    num -= 1;
    while(price != 0){
        if(price >= coin[num]){
            price -= coin[num];
            result += 1;
        }
        else{
            num -= 1;
        }
    }

    cout << result << endl;
    return 0;
}