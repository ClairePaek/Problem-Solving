#include <iostream>
#include <cstdio>
using namespace std;

int N, L;
int board[100][100];
bool isSlope[100][100];
int checkLine[100];
int answer;
bool isSame;

void Input(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }
}

void arrClear(){
    for(int i=0; i<N; i++){
        checkLine[i] = 0;
    }
}

int IsSame(int j){
    for(int l=0; l<L; l++){
        checkLine[j+1+l] = 1;
    }
    
    return j+L-1;
}

void IsSame2(int j){
    for(int l=0; l<L; l++){
        checkLine[j-l] = 1;
    }
}

void CheckWidth(){
    for(int i=0; i<N; i++){
        arrClear();
        for(int j=0; j<N; j++){
            isSame = true;
            if(j == N-1){
                answer++;
                for(int k=0; k<N; k++){
                    if(checkLine[k] == 1) 
                        isSlope[i][k] = checkLine[k];
                }
            }
            else if(board[i][j+1] - board[i][j] == 1){
                for(int l=0; l<L; l++){
                    if((j-l < 0) || board[i][j] != board[i][j-l] || checkLine[j-l]){
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                    IsSame2(j);
                else
                    break;
            }

            else if(board[i][j+1]-board[i][j] == -1){
                isSame = true;
                for(int l=0; l<L; l++){
                    if((j+l+1 >= N) || board[i][j+1] != board[i][j+1+l] || checkLine[j+1+l]){
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                    j = IsSame(j);
                else
                    break;
            }
            else if(abs(board[i][j+1] - board[i][j]) >= 2) break;
        }
    }
}

void CheckHeight(){
    for(int i=0; i<N; i++){
        arrClear();
        for(int j=0; j<N; j++){
            if(j == N-1){
                answer++;
                for(int k=0; k<N; k++){
                    if(checkLine[k] == 1)
                        isSlope[k][i] = checkLine[k];
                }
            }
            else if(board[j+1][i]-board[j][i] == 1){
                isSame = true;
                for(int l=0; l<L; l++){
                    if((j-l < 0) || board[j][i] != board[j-1][i] || checkLine[j-l]){
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                    IsSame2(j);
                else
                    break;
            }
            else if(board[j+1][i]-board[j][i] == -1){
                isSame = true;
                for(int l=0; l<L; l++){
                    if((j+l+1 >= N) || board[j+1][i] != board[j+1+l][i] || checkLine[j+1+l]){
                        isSame = false;
                        break;
                    }
                }
                if(isSame)
                    j = IsSame(j);
                else
                    break;
            }
            else if(abs(board[j+1][i] - board[j][i]) >= 2) break;
        }
    }
}

void Solution(){
    CheckWidth();
    CheckHeight();
    cout << answer << '\n';
}   

int main(){
    Input();
    Solution();
}