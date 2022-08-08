#include <iostream>
#include <cstdio>
using namespace std;

int N, M, start_x, start_y, K;
int board[20][20];
int *directions; 
int dice[7] = {0,};
int dx[] = {0, 1, -1, 0, 0}; //동 서 북 남
int dy[] = {0, 0, 0, -1, 1}; 

void Movedice(int dir){
    int temp;
    switch(dir){
        case 1:
            temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
            break;

        case 2:
            temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
            break;

        case 3:
            temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
            break;

        case 4:
            temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
            break;
    }
}

void Solution(){
    int x, y, nx, ny, dir;
    x = start_x;
    y = start_y;

    for(int k=0; k<K; k++){
        dir = directions[k];
        nx = x + dx[dir];
        ny = y + dy[dir];
        
        if(nx < 0 || nx > M-1 || ny < 0 || ny > N-1)
            continue;
        
        Movedice(dir);

        if(board[ny][nx] == 0)
            board[ny][nx] = dice[6];
            
        else{
            dice[6] = board[ny][nx];
            board[ny][nx] = 0;
        }

        x = nx;
        y = ny;
        printf("%d\n", dice[1]);
    }
}

void Input(){
    cin >> N >> M >> start_y >> start_x >> K;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            scanf("%d", &board[n][m]);
        }
    }

    directions = new int [K];
    for(int k=0; k<K; k++){
        scanf("%d", &directions[k]);
    }
}

int main(){
    Input();
    Solution();
}