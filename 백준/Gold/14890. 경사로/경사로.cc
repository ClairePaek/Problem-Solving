#include <iostream>
#include <cstdio>
using namespace std;

int N, L;
int board[100][100];
bool isSlope[100][100];
int answer;

void Input(){
    cin >> N >> L;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &board[i][j]);
        }
    }
}

void BoardCheck(){
    for(int i=0; i<N; i++){
        int checkLine[N];
        for(int j=0; j<N; j++){
            checkLine[j] = 0;
        }

        for(int j=0; j<N; j++){
            bool isSame = true;

            if(j == N-1){
                answer++;
                for(int k=0; k<N; k++){
                    if(checkLine[k] == 1)
                        isSlope[i][k] = checkLine[k];
                }
            }
            else if(board[i][j+1]-board[i][j] == 1){
                if(checkLine[j])
                    isSame = false;
                else{
                    for(int l=0; l<L; l++){
                        if((j-l < 0) || board[i][j] != board[i][j-l] || checkLine[j-l]){
                            isSame = false;
                            break;
                        }
                    }
                }
                if(isSame){
                    for(int l=0; l<L; l++){
                        checkLine[j-l] = 1;
                    }
                }
                else
                    break;
            }

            else if(board[i][j+1]-board[i][j] == -1){
                bool isSame = true;
                if(checkLine[j+1])
                    isSame = false;
                else{
                    for(int l=1; l<L; l++){
                        if((j+l >= N) || board[i][j+1] != board[i][j+1+l] || checkLine[j+1+l]){
                            isSame = false;
                            break;
                        }
                    }
                }
                if(isSame){
                    for(int l=0; l<L; l++){
                        checkLine[j+1+l] = 1;
                    }
                    j = j+L-1;
                }
                else
                    break;
            }
            else if(abs(board[i][j+1] - board[i][j]) >= 2){
                break;
            }
        }
    }
    
    for(int i=0; i<N; i++){
        int checkLine[N];
        for(int j=0; j<N; j++){
            checkLine[j] = 0;
        }
        
        for(int j=0; j<N; j++){
            if(j == N-1){
                answer++;
                for(int k=0; k<N; k++){
                    if(checkLine[k] == 1)
                        isSlope[k][i] = checkLine[k];
                }
            }

            else if(board[j+1][i]-board[j][i] == 1){
                bool isSame = true;
                if(checkLine[j])
                    isSame = false;
                else{
                    for(int l=1; l<L; l++){
                        if((j-l < 0) || board[j][i] != board[j-1][i] || checkLine[j-l]){
                            isSame = false;
                            break;
                        }
                    }
                }
                if(isSame){
                    for(int l=0; l<L; l++){
                        checkLine[j-l] = 1;
                    }
                }
                else
                    break;
            }
            else if(board[j+1][i]-board[j][i] == -1){
                bool isSame = true;
                if(checkLine[j+1])
                    isSame = false;
                else{
                    for(int l=1; l<L; l++){
                        if((j+l >= N) || board[j+1][i] != board[j+1+l][i] || checkLine[j+1+l]){
                            isSame = false;
                            break;
                        }
                    }
                }
                if(isSame){
                    for(int l=0; l<L; l++){
                        checkLine[j+1+l] = 1;
                    }
                    j = j+L-1;
                }
                else
                    break;
            }
            else if(abs(board[j+1][i] - board[j][i]) >= 2){
                break;
            }
        }
    }
}
void Solution(){
    BoardCheck();
    cout << answer << '\n';
}   

int main(){
    Input();
    Solution();
}