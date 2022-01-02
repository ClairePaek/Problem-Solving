#include<iostream>
using namespace std;

int N;
int Operator[4]; // + - * /
int operand[11];
int max_num = -1000000000;
int min_num = 1000000000;

void Input(){
    cin >> N; 
    for(int n=0; n<N; n++){
        cin >> operand[n];
    }
    for(int i=0; i<4; i++){
        cin >> Operator[i];
    }
}

void Match(int idx, int answer){
    int n_answer;

    if(idx == N-1){
        if(min_num > answer)
            min_num = answer;
        if(max_num < answer)
            max_num = answer;
    }

    for(int i=0; i<4; i++){
        if(Operator[i] > 0){ //연산자가 있으면
            switch (i)
            {
            case 0:
                n_answer = answer + operand[idx+1];
                break;
            case 1:
                n_answer = answer - operand[idx+1];
                break;
            case 2:
                n_answer = answer * operand[idx+1];
                break;
            case 3:
                n_answer = answer / operand[idx+1];
                break;
            }
            Operator[i] --;
            Match(idx+1, n_answer);
            Operator[i] ++;
        }
    }
}

void Solution(){
    Match(0, operand[0]);
    cout << max_num <<'\n';
    cout << min_num <<'\n';
}

int main(){
    Input();
    Solution();
}
