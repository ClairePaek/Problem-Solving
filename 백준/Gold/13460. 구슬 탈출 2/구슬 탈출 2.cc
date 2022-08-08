#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int answer = 11;  
char board[10][10];
int R[2], B[2];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int getDist(int x1, int y1, int x2, int y2){
    int dist = abs(x1 - x2) + abs(y1 - y2);
    return dist;
}

int InverseDir(int dir){
    switch(dir){
        case 0:
            return 1;
        case 1:
            return 0;
        case 2:
            return 3;
        case 3:
            return 2;
    }

    return -1;
}

void Move(int Ry, int Rx, int By, int Bx, int cnt, int dir){ 
    if(cnt < answer){ // cur_cnt가 10이 넘으면 또는 현재 답 이상이면 종료한다. 
        bool R_arrived = false;
        bool B_arrived = false;

        int nRx = Rx + dx[dir];
        int nRy = Ry + dy[dir];

        //빨간색을 움직인다. 
        while(1){ 
            if(board[nRy][nRx] == '#') break;
            else if(board[nRy][nRx] == 'O'){
                R_arrived = true; 
                break;
            }

            nRx += dx[dir];
            nRy += dy[dir]; 
        }

        nRx -= dx[dir];
        nRy -= dy[dir]; 
        
        //파란색을 움직인다.
        int nBx = Bx + dx[dir];
        int nBy = By + dy[dir];
        while(1){ 
            if(board[nBy][nBx] == '#') break;
            else if(board[nBy][nBx] == 'O'){
                B_arrived = true;
                break;
            }

            nBx += dx[dir];
            nBy += dy[dir]; 
        }
        
        nBx -= dx[dir];
        nBy -= dy[dir];

        if(B_arrived) return;

        if(R_arrived)
          answer = cnt;

        else if(nRx == nBx && nRy == nBy){
            int Rdist = getDist(nRx, nRy, Rx, Ry);
            int Bdist = getDist(nBx, nBy, Bx, By);

            if(Rdist > Bdist){
                nRx -= dx[dir];
                nRy -= dy[dir]; 
            }
            else{
                nBx -= dx[dir];
                nBy -= dy[dir];
            }
        }

        for(int i=0; i<4; i++){
            if(i == dir) continue;
            if(i == InverseDir(dir)) continue;
            Move(nRy, nRx, nBy, nBx, cnt+1, i);
        }
    }
}

void Solution(){
    for(int i=0; i<4; i++){
        Move(R[0], R[1], B[0], B[1], 1, i);
    }
    if(answer > 10){
        answer = -1;
    }
}

void Input(){
    cin >> N >> M; 

    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            cin >> board[n][m];
            if(board[n][m] == 'R'){
                R[0] = n;
                R[1] = m;
                board[n][m] = '.';
            }
            else if(board[n][m] == 'B'){
                B[0] = n;
                B[1] = m;
                board[n][m] = '.';
            }
        }
    }
}

int main(){
    Input();
    Solution();

    cout << answer;
}