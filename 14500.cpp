#include <iostream>
#include <cstdio>
using namespace std;

int N, M;
int board[501][501];
int answer = 0;
int poly[19][3][2] = {	// 19개의 테트로미노
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},

    {{0,1}, {1,0}, {1,1}},

    {{1,0}, {1,1}, {2,0}},
    {{0,1}, {0,2}, {1,1}},
    {{0,1}, {-1,1}, {1,1}},
    {{1,-1}, {1,0}, {1,1}},

    {{1,0}, {1,-1}, {2,-1}},
    {{1,0}, {1,-1}, {0,1}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    
    {{1,0}, {0,1}, {2,0}},
    {{1,0}, {2,-1}, {2,0}},
    {{1,0}, {2,1}, {2,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {0,2}, {-1,2}},
};


void Input(){
    scanf("%d %d", &N, &M);
    for(int n=0; n<N; n++){
        for(int m=0; m<M; m++){
            scanf("%d", &board[n][m]);
        }
    }
}

void Solution(){
    int nx, ny, sum;
    bool is_stay;

    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            for(int k=0; k<19; k++){
                is_stay = true;
                sum = board[y][x];
                for(int l=0; l<3; l++){
                    ny = y + poly[k][l][0];
                    nx = x + poly[k][l][1];

                    if(ny < 0 || ny > N-1 || nx<0 || nx > M-1){
                        is_stay = false;
                        break;
                    }
                    sum +=board[ny][nx];
                }
                
                if(is_stay && sum > answer)
                    answer = sum;
            }
        }
    }
}

int main(){
    Input();
    Solution();
    cout << answer << '\n';
}