#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[100001] = {0, };


/*
1부터 시작해서 큰 수로 가장 짧게 가는 횟수를 arr에 저장한다.
*/
void dp(int a, int check){
    if(arr[a] != 0 && arr[a] < check) 
        return;
    
    if(arr[a] == 0 || arr[a] > check)
        arr[a] = check;

    if(a * 3 <= N)
        dp(a * 3, check + 1);
    if(a * 2 <= N)
        dp(a * 2, check + 1);
    if(a + 1 <= N)
        dp(a + 1, check + 1);
    
    return;
}


int main()
{
    cin >> N;

    dp(1, 0);

    cout << arr[N];    

    return 0;

}