#include <iostream>
using namespace std;

int main(){
    int num;
    cin >> num;
    int arr[3000000] = {0,};         //반 공간 생성
    for(int i = 1; i < num; i++){    //arr[i]가 0인 경우는 이전에 건든적 없는 경우
        if(arr[i+1] == 0 || arr[i+1] > arr[i]+1) arr[i+1] = arr[i] + 1;   // 이미 저장된 값과 이번의 값중 작은값 저장
        if(arr[2*i] == 0 || arr[2*i] > arr[i]+1) arr[2*i] = arr[i] + 1;
        if(arr[3*i] == 0 || arr[3*i] > arr[i]+1) arr[3*i] = arr[i] + 1;    
    }

    cout << arr[num] << endl;

    return 0;
}