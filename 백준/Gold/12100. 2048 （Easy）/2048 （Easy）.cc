#include <iostream>
#include <cstring>
#include <algorithm>

#define MAX 20
using namespace std;

int N, answer;
int board[MAX][MAX];
int tmpBoard[MAX][MAX];
int directions[5];
bool visit[MAX][MAX];

void Input(){
    cin >> N;
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            cin >> board[y][x];
        }
    }
}

void boardCopy(){
    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            tmpBoard[y][x] = board[y][x];
        }
    }
}

void Move_Left()
{
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N - 1; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int nx = x + 1;
                while (nx < N)
                {
                    if (tmpBoard[y][nx] != 0)
                    {
                        isFind = true;
                        break;
                    }
                    nx++;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[y][nx]);
            }
        }
    }
 
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N - 1; x++){
            if (tmpBoard[y][x] == tmpBoard[y][x+1]){
                tmpBoard[y][x] += tmpBoard[y][x];
                tmpBoard[y][x+1] = 0;
            }
        }
    }
 
    for (int y = 0; y < N; y++){
        for (int x = 0; x < N - 1; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int nx = x + 1;
                while (nx < N)
                {
                    if (tmpBoard[y][nx] != 0)
                    {
                        isFind = true;
                        break;
                    }
                    nx++;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[y][nx]);
            }
        }
    }
}
 
void Move_Right()
{
    for (int y = 0; y < N; y++){
        for (int x = N-1; x>0; x--){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int nx = x-1;
                while (nx>=0){
                    if (tmpBoard[y][nx] != 0){
                        isFind = true;
                        break;
                    }
                    nx--;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[y][nx]);
            }
        }
    }
 
    for (int y=0; y<N; y++){
        for (int x = N-1; x>0; x--){
            if (tmpBoard[y][x] == tmpBoard[y][x-1]){
                tmpBoard[y][x] += tmpBoard[y][x];
                tmpBoard[y][x-1] = 0;
            }
        }
    }
 
    for (int y = 0; y < N; y++){
        for (int x = N-1; x>0; x--){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int nx = x-1;
                while (nx>=0){
                    if (tmpBoard[y][nx] != 0){
                        isFind = true;
                        break;
                    }
                    nx--;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[y][nx]);
            }
        }
    }
}
 
void Move_Up()
{
    for (int y=0; y<N-1; y++){
        for (int x = 0; x < N; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int ny = y+1;
                while (ny <= N-1){
                    if (tmpBoard[ny][x] != 0){
                        isFind = true;
                        break;
                    }
                    ny++;
                }
 
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[ny][x]);
            }
        }
    }
 
    for (int y = 0; y < N-1; y++){
        for (int x = 0; x < N; x++){
            if (tmpBoard[y][x] == tmpBoard[y+1][x]){
                tmpBoard[y][x] += tmpBoard[y][x];
                tmpBoard[y+1][x] = 0;
            }
        }
    }
 
    for (int y=0; y<N-1; y++){
        for (int x = 0; x < N; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int ny = y+1;
                while (ny <= N-1){
                    if (tmpBoard[ny][x] != 0){
                        isFind = true;
                        break;
                    }
                    ny++;
                }
 
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[ny][x]);
            }
        }
    }
}
 
void Move_Down(){
    for (int y = N-1; y>0; y--){
        for (int x = 0; x < N; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int ny = y-1;
                while (ny >= 0){
                    if (tmpBoard[ny][x] != 0){
                        isFind = true;
                        break;
                    }
                    ny--;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[ny][x]);
            }
        }
    }
 
    for (int y = N-1; y > 0; y--){
        for (int x = 0; x < N; x++){
            if (tmpBoard[y-1][x] == tmpBoard[y][x]){
                tmpBoard[y][x] += tmpBoard[y][x];
                tmpBoard[y-1][x] = 0;
            }
        }
    }

    for (int y = N-1; y>0; y--){
        for (int x = 0; x < N; x++){
            bool isFind = false;
            if (tmpBoard[y][x] == 0){
                int ny = y-1;
                while (ny >= 0){
                    if (tmpBoard[ny][x] != 0){
                        isFind = true;
                        break;
                    }
                    ny--;
                }
                if (isFind)
                    swap(tmpBoard[y][x], tmpBoard[ny][x]);
            }
        }
    }
 
}

void Move(){
    for(int i=0; i<5; i++){
        int Dir = directions[i];
        if (Dir == 0) Move_Right();
        else if (Dir == 1) Move_Left();
        else if (Dir == 2) Move_Down();
        else Move_Up();
    }

    for(int y=0; y<N; y++){
        for(int x=0; x<N; x++){
            answer = max(answer, tmpBoard[y][x]);
        }
    }
}

void Select_Direction(int Cnt){
    if(Cnt == 5){
        boardCopy();
        Move();
        return;
    }

    for(int i=0; i<4; i++){
        directions[Cnt] = i;
        Select_Direction(Cnt+1);
    }
}


void Solution(){
    Select_Direction(0);
    cout << answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solution();
}