#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//dfs: 깊이우선탐색, 위에서 아래로 정점간 연결된 노드를 따라 끝점이 나타날 때 까지 순서대로  탐색
void dfs(int* t1, int* t2, int n_th) {
    // t1[n_th] = 1 -> 끝점을 의미(다음으로 탐색할 정점이 없음)
    if (t1[n_th] == 1)
        return;

    t1[n_th] = 1; // j번째 정점을 지나갔음을 의미
    dfs(t1, t2, t2[n_th]);  // t2 체크
}//end dfs

int main() {

    // n1: 테스트 케이스, n2: 순열 개수 , cnt[j]: j번째 순열사이클의 개수
    int n1, n2;
    int cnt[2000] = { 0, };

    int t1[2000] = { 0, }; //순서를 나타내는 행벡터  ex) 1 2 3 4 5
    int t2[2000] = { 0, }; //입력받은 순열의 행백터  ex) 4 1 3 2 5       

    //테스트 케이스 입력
    scanf("%d", &n1);

    //입력 받은 테스트 케이스만큼 반복
    for (int i = 0; i < n1; i++) {
        scanf("%d", &n2);

        // 순열 입력
        for (int j = 1; j < n2 + 1; j++) {
            scanf("%d", &t2[j]);
            t1[j] = 0; //for문이 한번 돌고난 후 다음 케이스의 순열사이클 확인을 위해 다시 0으로 초기화
        }

        for (int k = 1; k < n2 + 1; k++) {

            //탐색 시작
            if (t1[k] == 0) {
                dfs(t1, t2, k);
                cnt[i]++;
            }

        }
    }
    //테스트케이스 개수만큼 output 출력
    for (int j = 0; j < n1; j++)
        printf("%d\n", cnt[j]);

    return 0;
}//end main
