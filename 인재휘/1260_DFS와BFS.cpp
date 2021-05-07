#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define v_s 1002

int main(){
    int N, M, V, A_num, B_num;
    cin >> N >> M >> V;
    int BFS_V = V;             //BFS의 시작점
    int DFS_V = V;             //DFS의 시작점
    int DFS_N = N - 1;         //DFS의 남은 개수를 체크하기 위함
    int D_E = 0;               //DFS종료시점
    
    // #_NEXT는 2차 배열로 a와 b가 연결되어있을 경우 (a,b)와 (b,a)가 1로, 연결 안되어있다면 0으로 채워짐
    // #_complete는 1차 배열로 a가 이미 지나갔다면 1로, 아직 아무도 지나가지 않았다면 0으로 채워짐
    int D_NEXT[v_s][v_s] = {0, };
    int B_NEXT[v_s][v_s] = {0, };
    int B_complete[v_s] = {0, };
    int D_complete[v_s] = {0, };
    int change = 0;
    vector<int>DFS;
    vector<int>BFS;
    vector<int>D_END;
    list<int>B_END;
    for(int i = 0; i < M; i++){
        cin >> A_num >> B_num;
        D_NEXT[A_num][B_num] = 1;
        D_NEXT[B_num][A_num] = 1;
        B_NEXT[A_num][B_num] = 1;
        B_NEXT[B_num][A_num] = 1;
    }

// DFS 구현
    DFS.push_back(DFS_V);
    D_END.push_back(DFS_V);
    D_complete[DFS_V] = 1;
    while(DFS_N != 0){                        // D_NEXT함수를 통해 1로 채워진 부분을 확인할때까지 돌다 확인된 부분이 D_complete에서 0이면 추가, 아니면 0으로 바꾸고 패쓰
        for(int i = 1; i <= N; i++){
            D_E = 0;
            if(D_NEXT[DFS_V][i] != 0){
                D_NEXT[DFS_V][i] = 0;
                D_NEXT[i][DFS_V] = 0;
                if(D_complete[i] == 0){
                    DFS.push_back(i);
                    D_END.push_back(i);
                    D_complete[i] = 1;
                    DFS_V = i;
                    DFS_N -= 1;
                    D_E = 1;
                    break;
                }
            }
        }
        
        if(D_E == 0){
            D_END.pop_back();
            if(D_END.size() != 0)
                DFS_V = D_END[D_END.size() - 1];
            else
                DFS_N = 0;
        }
    }
    for(int i = 0; i < DFS.size(); i++){
        cout << DFS[i] << ' ';
    }    
    cout << endl;

    
// BFS 구현
    BFS.push_back(BFS_V);
    B_END.push_back(BFS_V);
    while(B_END.size() != 0){           //B_NEXT를 돌면서 1로 되어있는거는 모두 0으로 바꾸며 추가
        B_END.pop_front();
        for(int i = 1; i<= N; i++){
            if(B_NEXT[BFS_V][i] != 0){
                if(B_complete[i] == 0){
                    BFS.push_back(i);
                    B_END.push_back(i);
                    B_complete[i] = 1;
                }
                B_NEXT[BFS_V][i] = 0;
                B_NEXT[i][BFS_V] = 0;                
            }
        }
        if(B_END.size() != 0){
            BFS_V = B_END.front();
        }
    }
    for(int i = 0; i < BFS.size(); i++){
        cout << BFS[i] << ' ';
    }
    cout << endl;
    return 0;
}