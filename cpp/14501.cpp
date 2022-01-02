#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int T[16], P[16], DP[16] ;
int answer;


void Input(){
    cin >> N; 
    for(int n=0; n<N; n++){
        scanf("%d %d", &T[n], &P[n]);
        DP[n] = 0;
    }
}

void Solution(){
    for(int i=0; i<N; i++){
        //일을 했을 때
        if(i+T[i] <= N){
            DP[i+T[i]] = max(DP[i+T[i]], DP[i] + P[i]);
        }

        //일을 안함
        DP[i+1] = max(DP[i+1], DP[i]);
    }

    for(int i=0; i<=N; i++){
        if(DP[i] > answer)
            answer = DP[i];
    }
}

int main(){
    Input();
    Solution();
    cout << answer<<'\n';
}