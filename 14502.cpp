#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int board[8][8];
int tmpboard[8][8];
int N, M;
vector <int> x_coord;
vector <int> y_coord;
int answer = 0;

void BoardCopy(){
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            tmpboard[n][m] = board[n][m];
        }
    }
}

void BFS(int y, int x){
    tmpboard[y][x] = 2;

    if(x < M-1 && tmpboard[y][x+1] == 0){
        BFS(y, x+1);
    }
    if(x > 0 && tmpboard[y][x-1] == 0){
        BFS(y, x-1);
    }
    if(y > 0 && tmpboard[y-1][x] == 0){
        BFS(y-1, x);
    }
    if(y < N-1 && tmpboard[y+1][x] == 0){
        BFS(y+1, x);
    }
}

void Solution(){
    for(int i=0; i<x_coord.size(); i++){
        board[y_coord[i]][x_coord[i]] = 1;
        for(int j=i+1; j<x_coord.size(); j++){
            board[y_coord[j]][x_coord[j]] = 1;
            for(int k=j+1; k<x_coord.size(); k++){
                board[y_coord[k]][x_coord[k]] = 1;
                BoardCopy();
                int zeroCnt = 0;

                for(int n=0; n<N; n++){
                    for(int m=0; m<M; m++){
                        if(board[n][m] == 2)
                            BFS(n, m);
                    }
                }

                for(int n=0; n<N; n++){
                    for(int m=0; m<M; m++){
                        if(tmpboard[n][m] == 0)
                            zeroCnt++;
                    }
                }

                if(answer < zeroCnt)
                    answer = zeroCnt;

                board[y_coord[k]][x_coord[k]] = 0;
            }
            board[y_coord[j]][x_coord[j]] = 0;
        }
        board[y_coord[i]][x_coord[i]] = 0;
    }
}

void Input(){
    cin >> N >> M;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            scanf("%d", &board[n][m]);

            if(board[n][m] == 0){
                y_coord.push_back(n);
                x_coord.push_back(m);
            }
        }
    }
}

int main(){
    Input();
    Solution();
    cout << answer <<'\n';
}