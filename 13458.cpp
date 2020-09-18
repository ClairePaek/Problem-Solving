#include <iostream>
#include <cstdio>
using namespace std;

int N, B, C;
int student[1000001];
long long cnt;

void Input(){
    cin >> N;
    for(int n=0; n<N; n++){
        scanf("%d", &student[n]);
    }
    cin >> B >> C;
}

void Solution(){
    cnt = N;
    for(int n=0; n<N; n++){
        student[n] -= B;
        if(student[n] > 0){
            cnt += student[n] / C;
            if(student[n] % C > 0)
                cnt ++;
        }
    }
    cout << cnt;
}

int main(){
    Input();
    Solution();
}