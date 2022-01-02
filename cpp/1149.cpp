#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int RGBboard[1000][3];
int DP[1000][3];
int answer = 1000000;

void Input(){
    scanf("%d", &N);
    for(int n=0; n<N; n++){
        for(int m=0; m<3; m++){
            scanf("%d", &RGBboard[n][m]);
        }
    }
}

int addPrice(){
    for(int i=1; i<N; i++){
        for(int c = 0; c<3; c++){
            DP[i][c] = min(DP[i-1][(c+1)%3], DP[i-1][(c+2)%3]) + RGBboard[i][c];
        }
    }
    for(int c = 0; c<3; c++){
        if(answer > DP[N-1][c])
            answer = DP[N-1][c];
    }
    return answer;
}

void Solution(){
    DP[0][0] = RGBboard[0][0];
    DP[0][1] = RGBboard[0][1];
    DP[0][2] = RGBboard[0][2];
    cout << addPrice() << '\n';
}

int main(){
    Input();
    Solution();
}