#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000001];

void Calculation(){
    dp[N] = 0;
    for(int i=N-1; i>0; i--){
        dp[i] = 10000001;
    }

    for(int i=N; i>0; i--){
        if(i % 3 == 0)
            dp[i/3] = min(dp[i/3], dp[i] + 1);
        if(i % 2 == 0)
            dp[i/2] = min(dp[i/2], dp[i] + 1);
        dp[i-1] = min(dp[i-1], dp[i] + 1);
    }
}

int main(){
    cin >> N;
    Calculation();
    cout << dp[1] << '\n';
}