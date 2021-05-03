#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define v_s 1001

int main(){
    int N, M, V, A_num, B_num;
    cin >> N >> M >> V;
    int BFS_V = V;
    int DFS_V = V;
    int DFS_N = N - 1;
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
/* 수정중
    DFS.push_back(DFS_V);
    D_END.push_back(DFS_V);
    D_complete[DFS_V] = 1;
    while(DFS_N != 0){
        for(int i = 1; i <= N; i++){
            if(D_NEXT[DFS_V][i] != 0){
                D_NEXT[DFS_V][i] = 0;
                D_NEXT[i][DFS_V] = 0;
                if(D_complete[i] == 0){
                    DFS.push_back(i);
                    D_END.push_back(i);
                    D_complete[i] = 1;
                    DFS_V = DFS[DFS.size() - 1];
                    DFS_N -= 1;
                    break;
                }
            }
        }
        if(D_END.size() != 0){
            DFS_N = D_END[D_END.size() - 1];
            D_END.pop_back();
        }
    }
    for(int i = 0; i < BFS.size(); i++){
        cout << DFS[i] << ' ';
    }    
    cout << endl;

    */
// BFS 구현
    BFS.push_back(BFS_V);
    B_END.push_back(BFS_V);
    while(B_END.size() != 0){
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