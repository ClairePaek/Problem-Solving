#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int N;
int Sboard[20][20];
int ischeck[20];
int answer = 40000;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &Sboard[i][j]);
        }
    }
}

void Marking(int num, int start){
    if(num == N/2){
        int startNum = 0;
        int linkNum = 0;
        vector<int> startTeam;
        vector<int> linkTeam;
        for(int i=0; i<N; i++){
            if(ischeck[i] == 1){
                startTeam.push_back(i);
            }
            else{
                linkTeam.push_back(i);
            }
        }

        for(int i=0; i<startTeam.size(); i++){
            for(int j=i+1; j<startTeam.size(); j++){
                int first = startTeam[i];
                int second = startTeam[j];
                startNum += Sboard[first][second] + Sboard[second][first];
            }
        }
        for(int i=0; i<linkTeam.size(); i++){
            for(int j=i+1; j<linkTeam.size(); j++){
                int first = linkTeam[i];
                int second = linkTeam[j];
                linkNum += Sboard[first][second] + Sboard[second][first];
            }
        }
        int absVal = abs(linkNum - startNum);
        if(answer > absVal)
            answer = absVal;
    }

    else{
        for(int i=start; i<N; i++){
            ischeck[i] = 1;
            Marking(num+1, i+1);
            ischeck[i] = 0;
        }
    }
}

void Solution(){ 
    ischeck[0] = 1;
    Marking(1, 1);
    cout << answer <<'\n';
}

int main(){
    Input();
    Solution();
}