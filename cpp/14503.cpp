#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int y, x, dir, answer;
int board[50][50];
int isClean[50][50];
int dx[] = {0, 1, 0, -1}; //북 동 남 서 
int dy[] = {-1, 0, 1, 0};
void Move();
void Clean();

void Input(){
    cin >> N >> M;
    cin >> y >> x >> dir;
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            scanf("%d", &board[n][m]);
            isClean[n][m] = board[n][m];
        }
    }
}

void Move(){
    int ny, nx, ndir;
    // 네 방향 모두 청소가 되어있는 경우 
    if(isClean[y][x-1] == 1 && isClean[y][x+1] == 1 && 
        isClean[y-1][x] == 1 && isClean[y+1][x] == 1){ //네 방향 모두 청소가 되어있음 또는 벽
        
        ny = y - dy[dir]; //후진 좌표 
        nx = x - dx[dir];

        if(board[ny][nx] == 1){ // 뒤로 돌아갈 수 없는 경우 
            return;
        }
        else{ // 뒤로 돌아갈 수 있는 경우
            y = ny;
            x = nx;
            Move();
        }
    }
    else{
        ndir = dir-1;  //현재 방향을 기준으로 왼쪽
        if(ndir < 0) ndir = 3;
        ny = y + dy[ndir]; //회전해서 방문할 예정인 좌표
        nx = x + dx[ndir];
        if(isClean[ny][nx] == 1 ){ //벽거나 청소가 되어있음
            dir = ndir;
            Move();
        }
        else if(isClean[ny][nx] == 0){ //왼쪽 방향에 청소하지 않은 공간이 존재한다면 전진
            y = ny;
            x = nx;
            dir = ndir;
            Clean();
        }
    }
}

void Clean(){
    isClean[y][x] = 1; // 현재 위치를 청소한다.
    answer++;

    Move();
}

void Solution(){
    Clean();
}

int main(){
    Input();
    Solution();
    cout << answer <<'\n';
}